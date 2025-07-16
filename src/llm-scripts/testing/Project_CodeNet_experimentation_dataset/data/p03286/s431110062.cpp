#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const double pi=3.14159265;
int main(){
  int n;
  cin>>n;
  if(n==0){
    cout<<0<<endl;
    return 0;
  }
  string s;
  int p=n;
  int q;
  while(p!=1){
    q=abs(p%(-2));
    if(p<0) p--;
    p/=(-2);
    s+=q+'0';
  }
  cout<<1;
  rep(i,s.size()){
    cout<<s[s.size()-i-1];
  }
}