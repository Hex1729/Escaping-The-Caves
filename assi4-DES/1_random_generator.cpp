#include <bits/stdc++.h>
using namespace std;

/* This code generates 1 lakh random binary strings of length 64 in the file "f1_random_strings" */

int main()
{
    char arr[64];
    long long int num;
    FILE *fpoint;
    fpoint = fopen("f1_random_strings.txt", "w+");
    for(int i=0; i<100000; i++){
        for(int j=0; j<64; j++){
            num=rand()%2;
            arr[j]=num+48;
        }
        for(int j=0; j<64; j++){
            fprintf(fpoint, "%c", arr[j]);
        }
        fprintf(fpoint, "\n");
    }
}