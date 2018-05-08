#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,a,b;
    int c=0;
    cin>>n;
    if(1<=n && n<=pow(10,5))
    {
        a=n;
        while(n>0)
        {
            b=n%10;
            n=n/10;
            c=c*10+b;
        }
        cout<<a+c<<endl;
    }
    return 0;
}