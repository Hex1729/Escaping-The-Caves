#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
using namespace std;

int main()
{
    ifstream ifile1;
    ofstream ofile1;
    ifile1.open("gamma1.txt");
    ofile1.open("gamma.txt");

INT E[] = {
  32, 1, 2, 3, 4, 5,
  4, 5,6, 7, 8, 9,
  8, 9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17, 
  16, 17, 18, 19, 20, 21, 
  20, 21, 22, 23, 24, 25, 
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32, 1
};
    string str1,str2;
    while ( getline (ifile1,str1) )
    {
        getline (ifile1,str2);
        for (int i=0;i<48;i++)
            ofile1<<str1[E[i]-1];
        ofile1<<'\n';
    }
    return 0;
}