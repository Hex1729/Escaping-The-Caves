#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
getline(cin,s,'#');
int len,count = 0;
len = s.length();
for(int i=0;i<len;i++){
if(65<= s[i] && s[i] <= 90 || 97<= s[i] && s[i]<= 122) count++;
}
cout<<count;
    return 0;
}