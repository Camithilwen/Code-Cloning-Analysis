#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;

const ll MAXN = (ll)2e3+10;
const ll DIV = (ll)1e9+7;


int main(void) {
   ll N;
   cin>>N;
   string S;
   cin>>S;
   vector<int> ar(2*N);
   if (S[0]=='W' || S[2*N-1]=='W') {
      cout<<0<<endl;
      return 0;
   }
   ar[0] = 1;
   ar[2*N-1] = -1;
   rep(i,1,2*N) {
      if (S[i] == S[i-1]) {
         if (ar[i-1]==1) ar[i]=-1;
         else ar[i]=1;
      } else {
         if (ar[i-1]==1) ar[i] = 1;
         else ar[i] = -1;
      }
   }
   // rep(i,0,2*N) cout<<ar[i]<<endl;

   ll sum = 0;
   rep(i,0,2*N) sum+=ar[i];
   if (sum!=0) {
      cout<<0<<endl;
      return 0;
   }
   ll ans = 1;
   ll tmp = 0;
   for(int i = 2*N-1;i>=0;i--) {
      if (ar[i]==-1) {
         tmp++;
      } else {
         ans *= tmp;
         ans = ans%DIV;
         tmp--;
      }
   }
   // cout<<ans<<endl;
   rep(i,1,N+1) {
      ans *= i;
      ans = ans%DIV;
   }
   cout<<ans<<endl;

   return 0;
}