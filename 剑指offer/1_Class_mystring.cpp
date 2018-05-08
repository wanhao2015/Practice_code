#include<iostream>
#include<cstring>
using namespace std;
class Mystring
{
    public:
        Mystring();
        Mystring(char* str):cstr(str){}
        Mystring(const Mystring& str);
        //~Mystring();
        Mystring& operator=(const Mystring &str);
    public:
        char* cstr;
};
Mystring::Mystring()
{

}
Mystring::Mystring(const Mystring& str)
{
    this->cstr = new char[strlen(str.cstr)+1];
    strncpy(this->cstr,str.cstr,strlen(str.cstr));
}
Mystring& Mystring::operator=(const Mystring &str)
{
    if(this == &str)
        return *this;
    delete[] this->cstr;
    this->cstr = new char[strlen(str.cstr)+1];      //删除此句，编译没错，运行会报错
    strcpy(cstr,str.cstr);
    return *this;
}

int main()
{
    Mystring ss1;
    Mystring ss2("123445");
    ss1=ss2;
    Mystring ss3(ss1);
    cout<<ss1.cstr<<endl<<ss3.cstr<<endl;
    return 0;
}
