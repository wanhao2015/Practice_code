#include<iostream>
using namespace std;
int func(int n,int data[],int k,int d)
{
     
}

int main()
{
    int n;
    int k,d;
    while(cin>>n)
    {
        int* data=new int[n];
        for(int i=0;i<n;i++)
            cin>>data[i];
        cin>>k>>d;
        int result=func(n,data,k,d);
        cout<<result<<endl;
    }
    return 0;
}