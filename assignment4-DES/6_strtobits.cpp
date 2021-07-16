#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *fi, *fo;
    fi = fopen("f4_outputs.txt", "r+");
    fo = fopen("f5_binarised_outputs.txt", "w+");
    long long int i = 0;
    char bin[65];
    char s[17];

    while (i<200000){
        fscanf(fi, "%s", s);
        for (int ind=0; ind<16; ind++){
            int x;
            x=(int)s[ind]-102;
            for(int j=0; j<4; j++){
                bin[4*ind+3-j]=(char)(x%2+48);
                x/=2;
            }
        }
        bin[64]='\0';
        i++;
        fprintf(fo, "%s\n", bin);
    }
}