#include <iostream>

using namespace std;

int main()
{
    int k,m,n=0;
    cin>>m>>k;
    int* data1 = new int [m];
    int* data2 = new int [m];
    for(int i=0;i<m;i++)
    {
        cin>>data1[i];
        if(data1[i]%k !=0)
            data2[n++] = data1[i];
    }
    int** a = new int*[n];
    for(int i=0;i<n;i++)
        a[i] = new int[n];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            a[i][j] = data2[i] + data2[j];
        }
    }
    int x=0;
    int sum=0;
    int* data3 = new int [n];
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<n;i++)
            data3[i]=0;
        data3[x++] = data2[i];
         for(int j=i+1;j<n;j++)
        {
            for(int l=x-1;l>=0;l--)
            {
                if((data3[l]+data2[j])%k !=0)
                    {
                        if(l == 0)
                            data3[x++] = data2[j];
                    }
                else
                    break;
            }
        }
        if(sum<x)
            sum = x;
        x=0;
    }
    cout << sum << endl;
    return 0;
}
