#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k;
  cin>>n>>k;    
  
  int a=n/100,b=k/100;
  int c=b-a-1;
  
  int aaf=(a/10)/10,aab=(a/10)%10;
  int bbf=(b/10)/10,bbb=(b/10)%10;
  int af=(n%100)/10,ab=(n%100)%10;
  int bf=(k%100)/10,bb=(k%100)%10;
    
  
  if(aab*10+aaf>=n%100){
    c+=1;
  }
  if(bbb*10+bbf<=k%100){
    c+=1;
  }
  cout<<c<<endl;
  
}