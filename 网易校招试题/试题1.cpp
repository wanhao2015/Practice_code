#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    string s="";
    cin>>n;
    if(1<=n && n<=pow(10,9))
    {
        while(n>0)
        {
            if(n%2==0)
            {
                n=(n-2)/2;
                s+='2';
            }
            else
            {
                n=(n-1)/2;
                s+='1';
            }
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}