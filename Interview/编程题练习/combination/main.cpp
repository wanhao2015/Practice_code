#include <iostream>
using namespace std;
#define MOD 1000000007

//long long func(int n,int m)
//{
//    if(n == m)
//        return 1;
//    if(m == 0)
//        return 1;
//    return func(n-1,m)+func(n-1,m-1);
//}
#define MAXN 105
long long conb[MAXN][MAXN];

void init()
{
    for(int i=0;i<MAXN;i++)
    {
        conb[i][0]=conb[i][i]=1;
        for(int j=1;j<i;j++)
        {
            conb[i][j]=conb[i-1][j]+conb[i-1][j-1];
            conb[i][j] %= MOD;
        }
    }
}

int main()
{
    int K,A,X,B,Y;
    cin>>K;
    cin>>A>>X>>B>>Y;
    long long sum=0;
    init();
    if(1<=K && K<=1000 && A!=B && A<=10 && X<=100 && B<=10 && Y<=100)
    {
        for(int i=0;i<=X;i++)
        {
            for(int j=0;j<=Y;j++)
            {
                if(A*i+B*j == K)
                {
                    //sum += (func(X,i)*func(Y,j))%MOD;
                    sum += (conb[X][i]*conb[Y][j])%MOD;
                    sum %=MOD;
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
