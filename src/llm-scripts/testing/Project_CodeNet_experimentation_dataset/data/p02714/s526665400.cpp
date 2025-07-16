#include <bits/stdc++.h>
 
using namespace std;
const long long INF = 1LL <<60;  
 
int main(void){
  long long res=0;
  long long i,j,k;
  long long l,m,h;
  string s;
  long long n_r=0,n_g=0,n_b=0;
  long long n_max=4010;
  long long n;
  long r[n_max]={},g[n_max]={},b[n_max]={};
 
  cin>>n;
  cin>>s;
  for(i=0;i<n;i++){
    if(s[i]=='R'){
      r[n_r]=i;
      n_r++;
    }
    else if(s[i]=='G'){
      g[n_g]=i;
      n_g++;
    }
    else{
      b[n_b]=i;
      n_b++;
    }
  }
  res=n_r*n_g*n_b;
  //cout<<n_r<<" "<<n_g<<" "<<n_b<<endl;
  
  for(i=0;i<n_r;i++){
    for(j=0;j<n_g;j++){
      h=max(r[i],g[j]);
      l=min(r[i],g[j]);
      if(2*l-h>=0 && s[2*l-h]=='B'){
        res--;
      }
      if(2*h-l<n && s[2*h-l]=='B'){
        res--;
      }
      if((h+l)%2==0 && s[(h+l)/2]=='B'){
        res--;
      }
    }
  }
    
  cout<<res<<endl;
  return 0;
}