#include <iostream>
using namespace std;

int main() 
{
    int rows;

    cout<<"Enter the number of rows: ";
    cin>>rows;

    if(rows<=0) 
    {
        cout<<"Please enter a positive number of rows." << std::endl;
        return; 
    }

    for(int i=1;i<=rows;++i) //outer loop
    { 
        for (int j=1;j<=i;++j) //inner loop
        { 
            cout<<"*";
        }
        cout<<endl; 
    }

    return 0;
}