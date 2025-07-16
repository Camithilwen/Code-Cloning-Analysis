#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T, typename ...Ts>
vector<T> fusion(vector<T> bs,Ts... ts){
  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};
  initializer_list<int>{(void(append(ts)),0)...};
  return bs;
}


// longest common prefix of s and s[i:n]
vector<int> zalgorithm(vector<int> s){
  int n=s.size();
  vector<int> as(n,0);
  as[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    as[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<n&&k+as[k]<j) as[i+k]=as[k],k++;
    i+=k;
    j-=k;
  }
  return as;
}

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>bs[i];

  vector<int> cs(n),ds(n);
  for(int i=0;i<n;i++){
    cs[i]=as[i]^as[(i+1)%n];
    ds[i]=bs[i]^bs[(i+1)%n];
  }

  vector<int> ss=fusion(ds,cs,cs);
  auto zs=zalgorithm(ss);
  for(int i=0;i<n;i++)
    if(zs[n+i]>=n) cout<<i<<" "<<(as[i]^bs[0])<<endl;

  return 0;
}
