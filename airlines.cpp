#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include<functional>

using namespace std;

// --- Flight record ---
struct Flight 
{
    int         no;
    string      name;
    int         seats;
    string      source;
    string      destination;
    float       charge;
    float       duration;

    void input() 
    {
        cout << "\nEnter flight no: ";
        cin >> no;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Flight name: ";
        getline(cin, name);

        cout << "No of seats: ";
        cin >> seats;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Source: ";
        getline(cin, source);

        cout << "Destination: ";
        getline(cin, destination);

        cout << "Ticket charge (Rs): ";
        cin >> charge;
        cout << "Time taken (hrs): ";
        cin >> duration;
    }

    void display() const 
    {
        cout << "\nFlight #" << no
             << "\n  Name       : " << name
             << "\n  Seats      : " << seats
             << "\n  From       : " << source
             << "\n  To         : " << destination
             << "\n  Charge     : Rs." << charge
             << "\n  Duration   : " << duration << " hrs\n";
    }

    void listLine() const 
    {
        cout << no << "\t" << name
             << "\t" << source << " -> " << destination
             << "\tRs." << charge << "\n";
    }
};

// --- Customer record ---
struct Customer 
{
    int         id;
    string      name;
    int         age;
    string      address;
    string      nationality;
    string      phone;

    void input() 
    {
        cout << "\nEnter customer ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name: ";
        getline(cin, name);

        cout << "Age: ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Address: ";
        getline(cin, address);

        cout << "Nationality: ";
        getline(cin, nationality);

        cout << "Phone No.: ";
        getline(cin, phone);
    }

    void display() const 
    {
        cout << "\nCustomer #" << id
             << "\n  Name        : " << name
             << "\n  Age         : " << age
             << "\n  Address     : " << address
             << "\n  Nationality : " << nationality
             << "\n  Phone       : " << phone << "\n";
    }

    void listLine() const 
    {
        cout << id << "\t" << name
             << "\t" << age
             << "\t" << phone << "\n";
    }
};

// --- Seat booking ---
struct Booking 
{
    int     flightNo;
    int     customerId;
    int     seatNo;
    int     day, month, year;

    void input() 
    {
        cout << "\nEnter seat number: ";
        cin >> seatNo;

        cout << "Booking date (DD MM YYYY): ";
        cin >> day >> month >> year;
    }

    void display() const 
    {
        cout << "\nBooking — Flight #" << flightNo
             << ", Customer #" << customerId
             << ", Seat #" << seatNo
             << ", Date: " << day << "/" << month << "/" << year << "\n";
    }
};

// --- File utilities ---
template<typename T>
void appendRecord(const string& filename, const T& rec) 
{
    ofstream out(filename, ios::binary | ios::app);
    out.write(reinterpret_cast<const char*>(&rec), sizeof(T));
}

template<typename T>
bool findRecord(const string& filename, function<bool(const T&)> predicate, T& result) {
    ifstream in(filename, ios::binary);
    T tmp;
    while (in.read(reinterpret_cast<char*>(&tmp), sizeof(T))) {
        if (predicate(tmp)) 
        {
            result = tmp;
            return true;
        }
    }
    return false;
}

template<typename T>
void listAll(const string& filename, function<void(const T&)> onEach) {
    ifstream in(filename, ios::binary);
    T tmp;
    while (in.read(reinterpret_cast<char*>(&tmp), sizeof(T))) {
        onEach(tmp);
    }
}

// --- Menus ---
void flightMenu() 
{
    int choice;
    do 
    {
        cout << "\n--- Flight Menu ---\n"
             << "1. Add flight\n"
             << "2. List flights\n"
             << "3. Search flight\n"
             << "4. Back\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) 
        {
        case 1: 
        {
            Flight f;
            f.input();
            appendRecord("flights.dat", f);
            break;
        }
        case 2:
            cout << "\nAll flights:\nNo\tName\tRoute\tCharge\n";
            listAll<Flight>("flights.dat", [](auto& f){ f.listLine(); });
            break;
        case 3: 
        {
            int no;
            cout << "Enter flight no to search: ";
            cin >> no;
            Flight found;
            if (findRecord<Flight>("flights.dat", [&](auto& f){ return f.no == no; }, found)) 
            {
                found.display();
            } 
            else 
            {
                cout << "Not found.\n";
            }
            break;
        }
        }
    } 
    while (choice != 4);
}

void customerMenu() 
{
    int choice;
    do 
    {
        cout << "\n--- Customer Menu ---\n"
             << "1. Add customer\n"
             << "2. List customers\n"
             << "3. Search customer\n"
             << "4. Back\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) 
        {
        case 1: 
        {
            Customer c;
            c.input();
            appendRecord("customers.dat", c);
            break;
        }
        case 2:
            cout << "\nAll customers:\nID\tName\tAge\tPhone\n";
            listAll<Customer>("customers.dat", [](auto& c){ c.listLine(); });
            break;
        case 3: 
        {
            int id;
            cout << "Enter customer ID to search: ";
            cin >> id;
            Customer found;
            if (findRecord<Customer>("customers.dat", [&](auto& c){ return c.id == id; }, found)) {
                found.display();
            } 
            else 
            {
                cout << "Not found.\n";
            }
            break;
        }
        }
    } 
    while (choice != 4);
}

void bookingMenu() 
{
    cout << "\n--- Book a Seat ---\n";
    Booking b;
    cout << "Enter flight no: ";
    cin >> b.flightNo;
    cout << "Enter customer ID: ";
    cin >> b.customerId;
    b.input();
    appendRecord("bookings.dat", b);
    cout << "Booked!\n";
}

int main() 
{
    int choice;
    do 
    {
        cout << "\n=== Airways Reservation System ===\n"
             << "1. Flight records\n"
             << "2. Customer records\n"
             << "3. Seat booking\n"
             << "4. Exit\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: flightMenu();    break;
        case 2: customerMenu();  break;
        case 3: bookingMenu();   break;
        }
    } 
    while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
