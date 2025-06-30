#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string name;
    cout<<"What's your name? ";
    cin>>name;

    cout<<"Hello, "<<name<<"! "<<endl;
    cout<<"Calculating your IQ..."<<endl;

    for (int i=0;i<15;i++) 
    {
        cout<<"."; 
        cout.flush();
        _sleep(1000); 
    }
    cout<<"\nResult: Error 404... IQ not found!"<<endl;
    cout<<"Just kidding, "<<name<<". You're awesome!"<<endl;

    return 0;
}
