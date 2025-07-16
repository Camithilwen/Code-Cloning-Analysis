#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  long n,m,p[1001];
  while(cin>>n>>m,n||m){
    for(int i=1;i<=n;++i) cin>>p[i];
    p[0]=0;
    vector<long> s(0);
    for(int i=0;i<=n;++i){
      for(int j=0;j<=n;++j) s.push_back(p[i]+p[j]);
    }
    sort(s.begin(),s.end());
    long a=0;
    for(vector<long>::iterator it=s.begin();*it<m/2;++it){
      a=max(a,*it+*(upper_bound(s.begin(),s.end(),m-*it)-1));
    }
    cout<<a<<endl;
  }
  return 0;
}