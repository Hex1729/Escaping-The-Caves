#include <iostream>

using namespace std;

int main(){
    char s[48],k[56]={};
    int a[48];
    for (int i=0;i<48;i++) {cin>>s[i];}
    
    for (int i=0;i<48;i++) cin>>a[i];
    for (int i=0;i<56;i++) k[i]='X';
    for (int i=0;i<48;i++) 
        k[a[i]-1]=s[i];
    for (int i=0;i<56;i++) cout<<k[i];
return 0;
}