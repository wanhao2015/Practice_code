#include<iostream>
using namespace std;
int main()
{
    int t,n;
    int A,B,C;
    int v;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        A=0;
        B=0;
        C=0;
        for(int j=0;j<n;j++)
        {
            cin>>v;
            if(v%2!=0)
                A++;
            else if(v%4==0)
                C++;
            else
                B++;
        }
        if(C>=A)
            cout<<"Yes"<<endl;
        else
        {
            if(A==C+1 && B==0 && C!=0)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
