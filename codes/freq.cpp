#include <iostream> 
#include <unordered_map> 
#include<string>
using namespace std; 
  
int main() {
  string s;
  getline(cin,s,'#');
  unordered_map<char, float> freq;
  int len,count;
  len = s.length();
  cin>>count;
  for(int i=0;i<len;i++){
    if(65<= s[i] && s[i] <= 90 || 97<= s[i] && s[i]<= 122) {
        if( freq.find(tolower(s[i])) == freq.end())   freq.insert({tolower(s[i]),100.0/count});
        else freq[tolower(s[i])] = freq[tolower(s[i])] + 100.0/count ;
    }
}
  cout << "char\tfreq\n"; 
    for (auto itr = freq.begin(); itr != freq.end(); itr++) { 
        cout << itr->first 
             << '\t' << itr->second << '\n'; 
    } 

    return 0; 
}  
