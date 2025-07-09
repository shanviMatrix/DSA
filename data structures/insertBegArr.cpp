#include<iostream>
using namespace std;
int main()
{
    int arr[10],n,x;
    cout<<"enter size of elements : ";
    cin>>n;
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"enter the element to be entered at the beginning : ";
    cin>>x;

    for(int i=n;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=x;
    n++;

    cout<<"Element is added to the beginning : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}
