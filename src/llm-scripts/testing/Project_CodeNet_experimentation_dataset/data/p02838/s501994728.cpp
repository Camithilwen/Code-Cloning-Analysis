#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

#define M 1000000007
#define gb(co, k) ((co)>>(k)&1)

int main(){
   int n;
   cin>>n;
   vector<ll> a(n);
   rep(i, n) cin>>a[i];

   vector<vector<int>> sb(n);
   rep(i, n) sb[i]=vector<int>(60);

   rep(i, n){
      rep(j, 60) sb[i][j]=((i==0)?0:sb[i-1][j]) + gb(a[i], j);
   }
   int ans=0;
   for(int i=1; i<n; i++) rep(j, 60){
      int c;
      if(gb(a[i], j))
         c=((ll)(i-sb[i-1][j]) * (((ll)1<<j)%M))%M;
      else
         c=((ll)sb[i-1][j] * (((ll)1<<j)%M))%M;
      ans=(ans+c)%M;
   }

   cout<<ans<<endl;
   return 0;
}
