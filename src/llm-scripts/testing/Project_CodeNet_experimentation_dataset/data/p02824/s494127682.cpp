#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,m,v,p,i;
  cin >> n >> m >> v >> p;
  vector<long long> a(n);
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  
  long long s;
  s=n-1;
  while(a.at(s)+m<a.at(p-1)){
    s--;
  }
  s++;
  
  long long t,V;
  V=n*m;
  t=p-1;
  while(V>=m*v&&t<s){
    t++;
    if(t==n){
      break;
    }
    V=V-(a.at(t-1)-a.at(t))*(t-p+1);
  }
  
  cout << t << endl;
}