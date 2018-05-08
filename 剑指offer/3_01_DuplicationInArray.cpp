#include<iostream>
#include<vector>
using namespace std;

bool duplicate(int number[],int length,int* duplication)
{
    if(number == nullptr || length<=0)
        return false;
    for(int i=0;i<length;i++)
    {
        while(number[i]!=i)
        {
           if(number[i]==number[number[i]])
            {
                *duplication=number[i];
                return true;
            }
            swap(number[i],number[number[i]]);
        }
    }
    return false;
}

int getduplication(const int number[],int len)
{
        if(number == nullptr || len<=0)
            return -1;
        int temp[len]={0};
        for(int i=0;i<len;i++)
        {
           if(temp[number[i]]==0)
               temp[number[i]]=number[i];
           else
               return number[i];
        }
        return -1;
}

int main()
{
    int aa[5]={3,2,1,4,4};
    int bb=getduplication(aa,5);
    cout<<bb<<endl;
    return 0;
}
