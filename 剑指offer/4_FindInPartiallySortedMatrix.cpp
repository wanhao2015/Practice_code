#include<iostream>
#include<vector>
using namespace std;

bool FindPartiallySortedMatrix(int* Matrix,int rows,int columns,int number)
{
    if(Matrix!=nullptr && rows>0 && columns>0)
    {
        int row,column;
        for(row=0,column=columns-1;row<rows && column>=0;)
        {
            if(number == Matrix[row*columns+column])
                return true;
            else if(number > Matrix[row*columns+column])
                column--;
            else
                row++;
        }
    }
    return false;
}

int main()
{
    return 0;
}
