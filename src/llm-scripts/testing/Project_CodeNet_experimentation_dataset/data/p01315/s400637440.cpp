#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using pii=pair<double,string>;

int main(){
  int n;
  while(cin >> n,n){

    vector<pii> v(n);
    rep(i,n){
      string l;
      int p,a,b,c,d,e,f,s,m;
      cin >> l>>p>>a>>b>>c>>d>>e>>f>>s>>m;

      auto time=a+b+c+m*(d+e);
      auto price=m*s*f - p;

      v[i]=make_pair((double)price/(double)time,l);
    }

    sort(v.begin(),v.end(),[](auto x,auto y)->bool{ 
          return x.first == y.first ? x.second < y.second : (x.first > y.first); 
        });

    for(auto i:v){
      cout<<i.second<<endl;
    }
    cout << "#" << endl;
  }
}

