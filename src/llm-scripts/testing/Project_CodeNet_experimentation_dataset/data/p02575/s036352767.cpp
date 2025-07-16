#include<bits/stdc++.h>
#define int long long
using namespace std;
using P=pair<int,int>;
signed main(){
  int H,W;
  cin>>H>>W;
  set<P> s;
  multiset<int> ans;
  for(int i=0;i<W;i++){
    s.insert({i,i}); 
    ans.insert(0);
  }
  int n=0;
  for(int i=0;i<H;i++){
    int a,b;
    cin>>a>>b;
    a--;
    int mx=-1;
    auto it=s.lower_bound({max(a,n),0});
    for(;it!=s.end() && (*it).first<=b;it=s.erase(it)){
      mx=max(mx,(*it).second);
      ans.erase(ans.find((*it).first-(*it).second));
    }
    if(b!=W){
      if(mx!=-1){
        s.insert({b,mx});
        ans.insert(b-mx);
      }
    }
    home:;
    printf("%d\n",ans.size()==0?-1:*ans.begin()+i+1);
    if(n>=a)n=max(n,b);
  }
}