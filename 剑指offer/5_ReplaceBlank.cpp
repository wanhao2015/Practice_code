#include<iostream>
#include<vector>
using namespace std;

//length为字符数组的总容量
void ReplaceBlank(char str[],int length)
{
    if(str == nullptr || length<=0)
        return;
    int icount=0;
    int len=0;
    for(int i=0;str[i]!='\0';i++)
    {
        len++;
        if(str[i]== ' ')
            icount++;
    }
    int LenOfOrigin=len;
    int LenOfNew=len+2*icount;
    if(LenOfNew > length)
        return;
    while(LenOfOrigin>=0 && LenOfNew>LenOfOrigin)
    {
        if(str[LenOfOrigin] == ' ')
        {
            str[LenOfNew--]='0';
            str[LenOfNew--]='2';
            str[LenOfNew--]='%';
        }
        else
        {
            str[LenOfNew--]=str[LenOfOrigin];
        }
        LenOfOrigin--;
    }
}

int main()
{
    char str[50]=" Bob, hello  world!  ";
    ReplaceBlank(str,50);
    cout<<str<<endl;
    return 0;
}
