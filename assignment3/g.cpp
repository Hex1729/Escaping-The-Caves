#include <iostream> 
#include <vector> 
#include<algorithm>

using namespace std; 
 
unsigned long long int modInverse(unsigned long long int a, unsigned long long int m)
{
    for (unsigned long long int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}
 
int main() {
  unsigned long long int p =  19807040628566084398385987581;
  unsigned long long int o1 = 11226815350263531814963336315;
  unsigned long long int o2 = 9190548667900274300830391220;
  unsigned long long int o3 = 4138652629655613570819000497;
    
  unsigned long long int temp1 = modInverse(modInverse(o1,p)*o2,p);
  unsigned long long int temp2 = modInverse(modInverse(o2,p)*o3,p);
  
   unsigned long long int temp3 = temp1;
   unsigned long long int temp4 = temp2;
    
    for(int i =1;i<493;i++) temp3 = (temp3*temp1)%p;
    for(int i =1;i<139;i++) temp4 = (temp4*temp2)%p;
 
unsigned long long int flag = modInverse(temp4,p);

unsigned long long int g = (temp3*flag)%p;
printf("%ulld",g);
    
  
  return 0;
}  
