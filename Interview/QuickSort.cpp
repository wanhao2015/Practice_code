#include <iostream>
using namespace std;

template<class T>
void Swap(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template<class T>
int PartionSort(T* data,int low,int high)
{
    int pivotkey=data[low];
    while(low<high)
    {
        while(low<high && data[high]>=pivotkey)
            high--;
        Swap(data[low],data[high]);
        while(low<high && data[low]<=pivotkey)
            low++;
        Swap(data[low],data[high]);
    }
    return low;
}

template<class T>
void QuickSort(T* data,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=PartionSort(data,low,high);
        QuickSort(data,low,pivot-1);
        QuickSort(data,pivot+1,high);
    }
}

int main()
{
    int data[6]={3,2,1,4,0,5};
    QuickSort(data,0,5);
    for(int i=0;i<6;i++)
        cout<<data[i]<<" ";
    cout << "Hello world!" << endl;
    return 0;
}



