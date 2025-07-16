#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> x(n);
  int64_t sb=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i)>>b.at(i);
    x.at(i)=a.at(i)+b.at(i);
    sb+=b.at(i);
  }
  sort(x.begin(),x.end(),greater<int>());
  int64_t sx=0;
  for(int i=0;i<n;i+=2)
    sx+=x.at(i);
  cout<<sx-sb<<endl;
}