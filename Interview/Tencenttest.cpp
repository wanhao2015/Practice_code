#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int temp1=n;
    int i;
    for(i=0;;i++)
    {
        if(pow(2,i)<=temp1 && temp1<pow(2,i+1))
            break;
    }
    int *data=new int[i+1];
    int icount=0;
    int k=i;
    while(temp1>0)
    {
        if(temp1>=pow(2,i))
        {
            temp1-=pow(2,i);
            icount++;
        }
        i--;
    }
    int result=k+2-icount;
    cout<<result<<endl;
    return 0;
}
