#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n+1,0);
  for(int i=1;i<=n;i++)
    cin>>a.at(i);
  vector<int> d(n+1);
  int s=0;
  for(int i=0;i<n;i++){
    d.at(i)=abs(a.at(i+1)-a.at(i));
    s+=d.at(i);
  }
  d.at(n)=abs(a.at(n));
  s+=d.at(n);
  for(int i=1;i<=n;i++){
    if(min({a.at(i-1),a.at(i),a.at((i+1)%(n+1))})==a.at(i)||max({a.at(i-1),a.at(i),a.at((i+1)%(n+1))})==a.at(i))
      cout<<s-2*min(d.at(i-1),d.at(i))<<endl;
    else
      cout<<s<<endl;
  }
}