#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
 
int main(){
  
  unsigned long long l,r;
  cin >> l >> r;
  
unsigned long long mi=INT_MAX,i=0,j=0;
  
 if(r/2019-l/2019!=0)
    cout << 0 << endl;
 else{
   l%=2019;
   r%=2019;
   while(l+i!=r){
     j=l+i;
     while(j!=r){
       j++;
       mi=min((l+i)%2019*j%2019%2019,mi);
       
     }
     i++;
   }
 
   
  cout << mi << endl;
}
 
    
  
}

