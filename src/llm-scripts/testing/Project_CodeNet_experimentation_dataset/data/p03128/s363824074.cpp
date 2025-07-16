#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }

int main(){
  ll inf = pow(10,5);
  // 各数について使うマッチ棒の数を記憶
  umap<int,int> mp;
  mp[1] = 2;
  mp[2] = 5;
  mp[3] = 5;
  mp[4] = 4;
  mp[5] = 5;
  mp[6] = 6;
  mp[7] = 3;
  mp[8] = 7;
  mp[9] = 6;
  
  int N,M; cin>>N>>M;
  int a[M]; CINA(a,M);
  sort(a,a+M,greater<int>());
  
  // i本使い切った時の最大桁数をdpで求める
  int dp[N+1]; FILL(dp,N+1,-inf);
  dp[0] = 0LL;
  for(int i=1;i<=N;++i){
    REP(j,M){
      int x = a[j];
      int num = mp[x];
      if(i-num>=0){ chmax(dp[i],dp[i-num]+1); }
    }
  }
  // 上位の桁から順に、条件を満たす最大の数を並べていく
  while(N>0){
    REP(j,M){
      int x = a[j];
      int num = mp[x];
      if( N-num<0){ continue;}
      if( dp[N-num] == dp[N]-1 ){
        cout << x;
        N -= num;
        break;
      }
    }
  }
  cout << "\n";
}
