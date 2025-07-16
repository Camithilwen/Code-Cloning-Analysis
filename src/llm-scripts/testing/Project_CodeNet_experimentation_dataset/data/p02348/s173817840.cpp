#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
const int INF=pow(2,31)-1;
std::vector<P> v(1e6,P(INF,-1));
int N=1;
void update(int a,int b,int c,int d,int k,int l,int r){
  if(r<=a||b<=l)return;
  if(a<=l&&r<=b)v[k]=P(c,d);
  else{
    update(a,b,c,d,k*2+1,l,(l+r)/2);
    update(a,b,c,d,k*2+2,(l+r)/2,r);
  }
}
int ma(int a){
  int k=a+N-1;
  P res=v[k];
  while(k){
    k=(k-1)/2;
    if(res.second<v[k].second)res=v[k];
  }
  return res.first;
}

signed main(){
  int n,M;
  cin>>n>>M;
  while(n>N)N*=2;
  std::vector<int> ans;

  for(int i=0;i<M;i++){
    int q;cin>>q;
    if(q){
      int a;cin>>a;
      ans.push_back(ma(a));
    }
    else{
      int s,t,x;cin>>s>>t>>x;
      update(s,t+1,x,i,0,0,N);
    }
  }
  for(int p:ans)cout<<p<<endl;
}

