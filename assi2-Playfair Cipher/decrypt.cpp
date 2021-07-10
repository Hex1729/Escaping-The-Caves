#include <iostream> 
#include <vector> 
#include<string>
using namespace std; 
  
//Uses key = "SECURITY" to form playfair matrix and decrypt the ciphertext using the matrix.
  
int mod5(int x) 
{   if(x<0) return (5+x)%5;
    else return (x % 5); 
} 
 
int main() {
    int x=0;
    int y=1;
    string s;
    getline(cin,s);
    int a[4];
    char matrix[5][5];
    vector<char>key {'S','E','C','U','R','I','T','Y'};
    int count =0,flag = 0;
    char temp = 'A';
    
    //matrix formation
      for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(count<8){
                matrix[i][j] = key[count] ;
                count ++;
            }
            else {
                if(temp == 'J') flag =1;
                for(int k =0;k<8;k++) if(key[k]==temp) flag =1;
                while(flag){
                    temp++;
                    flag =0;
                    if(temp == 'J') flag =1;
                    for(int k =0;k<8;k++) if(key[k]==temp) flag =1;
                }
                
               matrix[i][j] = temp;
               temp++;
        
            }
            
        }
    }
    
   //string decryption 
     for (; x < s.length() && y <s.length() ; ) { 
         
         for(;s[x]<65 || s[x] >90;x++);
         if(x==y) y++;
         for(;s[y]<65 || s[y] >90;) {
             y++;
             if(x==y) y++;
         }
          
          
          for (int p = 0; p < 5; p++) { 
             for (int q = 0; q < 5; q++) { 
                if (matrix[p][q] == s[x]) { 
                a[0] = p; 
                a[1] = q; 
            } 
                else if (matrix[p][q] == s[y]) { 
                a[2] = p; 
                a[3] = q; 
            } 
          } 
       } 
          
        if (a[0] == a[2]) { 
            s[x] = matrix[a[0]][mod5(a[1] - 1)]; 
            s[y] = matrix[a[0]][mod5(a[3] - 1)]; 
          
        } 
        else if (a[1] == a[3]) { 
            s[x] = matrix[mod5(a[0] - 1)][a[1]]; 
            s[y] = matrix[mod5(a[2] - 1)][a[1]]; 
        } 
        else { 
            s[x] = matrix[a[0]][a[3]]; 
            s[y] = matrix[a[2]][a[1]]; 
        }
        
        
        x = y+1;
        y = x+1;
    } 
    
    cout<<s;
    
    
    return 0; 
}  
