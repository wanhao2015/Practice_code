#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string s;
    int k=0;
    int len;
    cin>>s;
    len=s.length();
    if(1<=len && len<=50)
    {
        int i;
        for(i=0;i<len-1;)
        {
            int j;
            for(j=i+1;j<len;)
            {
                if(s[i]!=s[j])
                {
                    k++;
                    break;
                }
                else
                {
                    if(j==len-1)
                        k++;
                    j++;
                }
            }
            i=j;
        }
        if(i==len-1)
            k++;
        double x=(double)len/k;
        cout <<setprecision(2)<<std::fixed <<x <<endl;
    }
    return 0;
}
添加笔记
