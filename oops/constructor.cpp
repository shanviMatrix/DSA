#include<iostream>
using namespace std;

class A
{
    int x;
    public:

    A(int a)
    {
        x=a;
    }

    operator int()
    {
        return x;
    }
};

int main()
{
    A obj1(100);
    int R;
    R=obj1;
    cout<<R;

    return 0;
}
 