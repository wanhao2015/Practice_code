#include<iostream>
#include<string>
#include<vector>
using namespace std;

//最大公共字串
string stringcommon(string str1,string str2)
{
    int len1=str1.size();
    int len2=str2.size();
    string sstr1="";
    int c[len1+1][len2+1];
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i == 0 || j == 0)
                c[i][j]=0;
            else
            {
                if(str1[i-1] == str2 [j-1])
                {
                    c[i][j] = c[i-1][j-1]+1;
                    if(c[i][j] > sstr1.size())
                    {
                        sstr1=str1.substr(i-c[i][j],c[i][j]);
                    }
                }
                else
                {
                    c[i][j] = 0;
                }

            }
        }
    }
    return sstr1;
}

int max1(int &a,int &b)
{
    return (a > b ? a : b);
}

//最大公共子序列长度
void LCSLength(string str1,string str2,int c[][64])
{
    int len1=str1.size();
    int len2=str2.size();
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i == 0 || j == 0)
                c[i][j] =0;
            else
            {
                if(str1[i-1] == str2 [j-1])
                {
                    c[i][j] = c[i-1][j-1]+1;
                }
                else
                {
                    c[i][j] = max1(c[i][j-1],c[i-1][j]);
                }

            }
        }
    }
}


//返回最大公共子序列
string PrintLCS(string str1,int c[][64],int m,int n)
{
    int k=c[m][n];
    string s;
    s.resize(k);
    while(k>0)
    {
        if(c[m][n] == c[m-1][n-1]+1)
        {
            s.insert(0,1,str1[m-1]);
            //s[--k]=str1[m-1];
            k--;
            m--;
            n--;
        }
        else if(c[m][n] == c[m-1][n])
            m--;
        else
            n--;
    }
    return s;
}

//字符串反转
void Inverse(string& str1,string& str2)
{
    int len1=str1.size();
    string temp(len1,' ');
    for(int i=0;i<len1;i++)
        temp[i] = str1[len1-i-1];
    str2=temp;
}

int main()
{
    string str1,str2;
    cin>>str1;
    Inverse(str1,str2);
    cout<<str2<<endl;
    int c[64][64];
    string result1=stringcommon(str1,str2);
    LCSLength(str1,str2,c);
    string result2=PrintLCS(str1,c,str1.size(),str2.size());


    cout<<result1<<endl;
    cout<<result2<<endl;
    return 0;
}
