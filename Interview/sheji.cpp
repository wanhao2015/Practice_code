#include<iostream>
#include<cmath>
using namespace std;
int shootnum(int n,int dataX[],int dataY[]);
int main()
{
    int n;
    cin>>n;
    int* dataX=new int[n];
    int* dataY=new int[n];
    for(int i=0;i<n;i++)
        cin>>dataX[i];
    for(int i=0;i<n;i++)
        cin>>dataY[i];
    int b=shootnum(n,dataX,dataY);
    cout<<b<<endl;
    delete[] dataX;
    delete[] dataY;
    return 0;
}
int shootnum(int n,int dataX[],int dataY[])
{
    int maxshoot=0;
    if(n<4)
        maxshoot=n;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int dx1=dataX[i]-dataX[j];
            int dy1=dataY[i]-dataY[j];
            for(int k=0;k<n;k++)
            {
                if(k==i || k==j)
                    continue;
                int icount=3;
                for(int l=0;l<n;l++)
                {
                    if(l==i || l==j || l==k)
                        continue;
                    int dx3=dataX[k]-dataX[l];
                    int dy3=dataY[k]-dataY[l];
                    int dx4=dataX[i]-dataX[l];
                    int dy4=dataY[i]-dataY[l];
                    if(dy1*dy3+dx1*dx3==0 || dy1*dx4==dx1*dy4)
                        icount++;
                }
                if(icount>maxshoot)
                    maxshoot=icount;
            }
        }
    }
    return maxshoot;
}
