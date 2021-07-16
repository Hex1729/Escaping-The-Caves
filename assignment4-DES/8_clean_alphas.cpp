#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream ifile1;
    ofstream ofile1;
    ifile1.open("f6_1_alphas_crude.txt");
    ofile1.open("f6_3_alphas_final.txt");

int E[] = {
  32, 1, 2, 3, 4, 5,
  4, 5,6, 7, 8, 9,
  8, 9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17, 
  16, 17, 18, 19, 20, 21, 
  20, 21, 22, 23, 24, 25, 
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32, 1
};
    string s1,s2;
    while ( getline (ifile1,s1) )
    {
        getline (ifile1,s2);
        for (int i=0;i<48;i++)
            ofile1<<s1[E[i]-1];
        ofile1<<'\n';
    }
    return 0;
}