#include<iostream>
#include<string>
using namespace std;

string decimalToBinary(int n){
    string binary = "";
    if(n == 0) return "0";

    while(n > 0){
        int bit = n % 2;
        binary = to_string(bit) + binary;  
        n = n / 2;
    }

    return binary;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string binary = decimalToBinary(n);
    cout << "Binary: " << binary << endl;

    return 0;
}
