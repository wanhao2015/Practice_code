#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //scanf("%d\n",&n);
    vector<vector<int>> dataX;
    vector<vector<int>> dataY;
    int* a=new int[n];
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<4;j++)
        {
            int a;
            cin>>a;
            temp.push_back(a);
        }
        dataX.push_back(temp);
        temp.clear();
        for(int j=0;j<4;j++)
            {
                int a;
                cin>>a;
                temp.push_back(a);
            }
        dataY.push_back(temp);
        temp.clear();
        int aa[6];
        int bb[6];
        int cc[6];
        set<int> distance;
        aa[0]=dataX[i][0]-dataX[i][1];
        aa[1]=dataX[i][1]-dataX[i][2];
        aa[2]=dataX[i][2]-dataX[i][3];
        aa[3]=dataX[i][3]-dataX[i][0];
        aa[4]=dataX[i][0]-dataX[i][2];
        aa[5]=dataX[i][1]-dataX[i][3];
        bb[0]=dataY[i][0]-dataY[i][1];
        bb[1]=dataY[i][1]-dataY[i][2];
        bb[2]=dataY[i][2]-dataY[i][3];
        bb[3]=dataY[i][3]-dataY[i][0];
        bb[4]=dataY[i][0]-dataY[i][2];
        bb[5]=dataY[i][1]-dataY[i][3];
        for(int i=0;i<6;i++)
        {
            cc[i]=aa[i]*aa[i]+bb[i]*bb[i];
            distance.insert(cc[i]);
        }
        int len=distance.size();
        if(len == 2)
        {
            int dis1=*distance.begin();
            int dis2=*distance.rbegin();
            if(2*dis1 ==dis2)
                a[i]=1;
            else
                a[i]=0;
        }
        else
            a[i]=0;
        distance.clear();
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    delete [] a;
    return 0;
}
