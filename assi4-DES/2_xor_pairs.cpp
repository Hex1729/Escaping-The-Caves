#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Find the xor value from the characeteristic*/
    
    char diffhex[17]={'4','0','5','C','0','0','0','0','0','4','0','0','0','0','0','0','\0'};
    int diffbin[64];
    for(int i=0; i<16; i++){
        int x=((int)diffhex[i])-48;
        if(x>16) x-=7;
        for(int j=0; j<4; j++){
            diffbin[4*i+j]=x/((int)pow(2,3-j));
            x-=pow(2,3-j)*diffbin[4*i+j];
        }
    }
    
    /* Initial Permutation(IP) */

    int IP[] = {
    58,50,42, 34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54, 46, 38, 30, 22, 14,6,
    64, 56, 48, 40,32,24, 16, 8,
    57, 49, 41, 33,25,17, 9,1,
    59, 51,43,35,27,19,11,3,
    61,53,45,37,29,21,13, 5,
    63,55, 47,39,31,23,15,7};

    int invIP[]={
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25};
    
    int xorval[64];
    for(int i=0; i<64; i++){
        xorval[IP[i]-1]=diffbin[i];
    }
    
    int xorvalue[16];
    for(int i=0; i<16; i++){
        int val=0;
        for(int j=0; j<4; j++){
            val+=xorval[4*i+3-j]*pow(2,j);
        }
        xorvalue[i]=val;
    }
    
    
    /* Collecting input pairs with fixed xorval */
    
    FILE *fi, *fo;
    fi = fopen("f1_random_strings.txt", "r+");
    fo = fopen("f2_inputs.txt", "w+");
    int i=0;
    char arr1[64];
    long long int arr2[64];
    long long int a1,a2;
    char s1[17],s2[17];
   //int xorval[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0};

    while(i<100000)
    {
        fscanf(fi, "%s", arr1);
        
        for(int j=0; j<64; j++)
        {
            a1=arr1[j]-48;
            a2=xorval[j];
            arr2[j]=(a1^a2);
        }
        int ind=0;
        for(ind=0; ind<16; ind++)
        {
            s1[ind]=102 + 8*(arr1[4*ind]-48) + 4*(arr1[4*ind+1]-48) + 2*(arr1[4*ind+2]-48) + (arr1[4*ind+3]-48);
            s2[ind]=102 + (8*arr2[4*ind] + arr2[4*ind+1]*4 + 2*arr2[4*ind+2] + arr2[4*ind+3]);
        }
        s1[ind]='\0';
        s2[ind]='\0';
        fprintf(fo, "%s\n", s1);
        fprintf(fo, "%s\n", s2);
        i++;
    }
}
