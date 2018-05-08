#include<iostream>
#include<string>
using namespace std;
struct ELEMENT_STRU
{
     unsigned int uiElementLength;
     unsigned int uiElementValue;
};

string func1(char c)
{
    string s;
    while(c!=0)
    {
        if((c&0x1)==1)
            s.insert(0,"1");
        else
            s.insert(0,"0");
        c>>=1;
    }
    while(s.size()<8)
        s.insert(0,"0");
    return s;
}

int func2(string s)
{
    int aa=0;
    int bb=1;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='1')
            aa+=bb;
        bb<<=1;
    }
    return aa;
}

void Decode(unsigned int uiInputLen, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[])
{
    string ss1="";
    string ss2="";
    int start=0;

    for(unsigned int i=0;i<uiInputLen;i++)
    {
        ss1+=func1(aInputByte[i]);
    }
    for(unsigned int i=0;i<uiElementNum;i++)
    {
        ss2=ss1.substr(start,astElement[i].uiElementLength);
        start+=astElement[i].uiElementLength;
        astElement[i].uiElementValue=func2(ss2);
    }
}

int main()
{
    unsigned int uiInputLen;
    unsigned int uiElementNum;

    cin>>uiInputLen;
    unsigned char* aInputByte =new unsigned char[uiInputLen];
    for(int i=0;i<uiInputLen;i++)
        scanf("%x ",&aInputByte[i]);
        //cin>>aInputByte[i];
    cin>>uiElementNum;
    struct ELEMENT_STRU* astElement = new struct ELEMENT_STRU[uiElementNum];
    if(uiElementNum<=uiInputLen)
    {
        for(int i=0;i<uiElementNum;i++)
            cin>>astElement[i].uiElementLength;
    }
    Decode(uiInputLen,aInputByte,uiElementNum,astElement);
    for(int i=0;i<uiElementNum;i++)
        cout<<astElement[i].uiElementValue<<endl;
    delete[] aInputByte;
    delete[] astElement;
    return 0;
}
