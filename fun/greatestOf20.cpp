//greatest of 20
#include<iostream>
using namespace std;

class Number
{
    int n[20];
public:
    void get();
    operator int() const;
};

void Number::get()
{
    cout<<"Enter 20 numbers: \n";
    for(int i=0;i<20;i++)
    {
        cout<<"Enter element "<<i+1<< ": ";
        cin>>n[i];
    }
}

Number::operator int() const
{
    int GREATEST=n[0];
    for(int i=1;i<20;i++)
    {
        if(GREATEST<n[i])
        {
            GREATEST=n[i];
        }
    }
    return GREATEST;
}

int main()
{
    Number obj1;
    int R;
    obj1.get();
    R=obj1;
    cout<<"Greatest  "<<R<<endl;

    return 0;
} 

