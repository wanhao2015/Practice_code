#include <iostream>
#include <cstring>

using namespace std;

char* multi(char* number_a, char* number_b) {

    int len_a = strlen(number_a); //计算长度
    int len_b = strlen(number_b);

    int* num_arr = new int[len_a+len_b];
    memset(num_arr, 0, sizeof(int)*(len_a+len_b)); //置0

    for (int i=len_a-1; i>=0; --i) { //计算每一位
        for (int j=len_b-1; j>=0; --j) {
        num_arr[i+j+1] += (number_b[j]-'0')*(number_a[i]-'0');
        }
    }

    for (int i=len_a+len_b-1; i>=0; --i) { //进位
        if (num_arr[i] >= 10) {
            num_arr[i-1] += num_arr[i]/10;
            num_arr[i] %= 10;
        }
    }

    char* result = new char[len_a+len_b+1];

    for( int i=0; i<(len_a+len_b); ++i){
        result[i] = (char)(((int)'0')+num_arr[i]);
    }
    result[len_a+len_b] = '\0'; //添加结束符

    delete[] num_arr;

    return result;
    //delete[] r;
}

int main(void){
    //char* number_a = "10089328947197491751797009791032";
    //char* number_b = "837190274291741974109721921321451";
    char* number_a=new char[1000];
    char* number_b=new char[1000];
    cin>>number_a>>number_b;
    std::cout << number_a << " * " << number_b << " = " << std::endl;

    char* result = multi(number_a, number_b);
    char* rr=result;
    if(*number_a=='0' || *number_b=='0')
        cout<<"0"<<endl;
    else
    {
        for(int i=0;i<strlen(number_a)+strlen(number_b);i++)
        {
            if(result[i]=='0')
            {
                rr++;
            }
            else
            {
                std::cout << rr << std::endl;
                break;
            }
        }
    }
    delete[] result;
    delete[] number_a;
    delete[] number_b;
    return 0;
}
