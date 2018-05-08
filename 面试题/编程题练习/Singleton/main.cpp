#include<iostream>
#include<vector>
using namespace std;
class Singleton1
{
    private:
        Singleton1();
        static Singleton1* mptr;
    public:
        int a;
        static Singleton1* Instance()
        {
            if(mptr == nullptr)
                mptr = new Singleton1();
            return mptr;
        }
};
Singleton1::Singleton1()
{
}
Singleton1* Singleton1::mptr=nullptr;		//静态成员变量必须在类外初始化。
int main()
{
    Singleton1* mptr1 = Singleton1::Instance();
    printf("%p\n",mptr1);
    Singleton1* mptr2 = Singleton1::Instance();
    printf("%p\n",mptr2);
    mptr1->a=6;
    //mptr1->Singleton1::mptr=nullptr;
    return 0;
}
