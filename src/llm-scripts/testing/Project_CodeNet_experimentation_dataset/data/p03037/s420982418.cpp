#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  cin>>N>>M;
  vector<long long> l(M);
  vector<long long> r(M);
  for(long long i=0;i<M;i++)
    cin>>l.at(i)>>r.at(i);
  sort(l.begin(),l.end());
  sort(r.begin(),r.end());
  long long a=r.at(0)-l.at(M-1)+1;
  if(a>0)
  cout<<a<<endl;
  else
    cout<<0<<endl;
}