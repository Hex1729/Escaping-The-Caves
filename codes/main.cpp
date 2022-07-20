#include <bits/stdc++.h>
using namespace std;

int main()
{
    FILE *fi, *fo;
    fi = fopen("freq_outputs.txt", "r+");
    fo = fopen("output1.txt", "w+");
    long long int i = 0;
    // long long int k;
    char temp[65];
    // long long int temp2[64];
    // long long int t1, t2;
    char s1[17];
    // int s[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (i < 200000)
    {
        fscanf(fi, "%s", s1);
        
        for (int l = 0; l < 16; l++)
        {
            int x;
            x=(int)s1[l]-102;
            for(int j = 0; j < 4; j++)
            {
                temp[4*l+3-j]=(char)(x%2+48);
                x/=2;
            }
        }
        temp[64] = '\0';
        // s2[l] = '\0';
        i++;
        fprintf(fo, "%s\n", temp);
        // fprintf(fo, "%s\n", s2);
    }
}