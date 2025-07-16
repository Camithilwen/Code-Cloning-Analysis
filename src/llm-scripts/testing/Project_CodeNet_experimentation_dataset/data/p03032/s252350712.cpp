#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

ll solve(int N,int K,vector<ll> A){
  deque<ll> deq2;
  REP(i,N){
    deq2.push_back(A[i]);
  }
  

  ll MAX = 0;
  REP(i,K+1){
    if(i>=N){
      vector<ll> vec=A;
      if(vec.size()>0){
        sort(ALL(vec));
        ll sum = 0;
        REP(k,vec.size()){
          sum+=vec[k];
        }
        REP(k,min(sz(vec),K-i)){
          if(vec[k]<0){
            sum-=vec[k];
          }
        }
        MAX=max(MAX,sum);
      }
    }else{
      REP(j,i+1){
        vector<ll> vec;
        deque<ll> deq=deq2;
        REP(k,j){
          vec.push_back(deq.front());
          deq.pop_front();
        }
        REP(k,i-j){
          vec.push_back(deq.back());
          deq.pop_back();
        }
        if(vec.size()>0){
          sort(ALL(vec));
          // REP(k,vec.size()){
          //   cout << vec[k] << " ";
          // }
          // cout << endl;
          ll sum = 0;
          REP(k,vec.size()){
            sum+=vec[k];
          }
          REP(k,min(sz(vec),K-i)){
            if(vec[k]<0){
              sum-=vec[k];
            }
          }
          MAX=max(MAX,sum);
          // cout << MAX << endl;
          // cout << i << "a" << j << endl;
        }
      }
    }
  }

  return MAX;
}

ll dfs(deque<ll> deq,vector<ll> A,int cnt,int K){
  ll ret = 0;
  REP(i,sz(A)){
    ret+=A[i];
  }
  if(cnt==K){
    return ret;
  }
  cnt++;
  ll MAX = ret;
  REP(i,sz(A)){
    vector<ll> B=A;
    deque<ll> deq2=deq;
    deq2.push_back(B[i]);
    B.erase(B.begin()+i);
    MAX=max(MAX,dfs(deq2,B,cnt,K));
    deque<ll> deq3=deq;
    vector<ll> C=A;
    deq3.push_front(C[i]);
    C.erase(C.begin()+i);
    MAX=max(MAX,dfs(deq3,C,cnt,K));
  }
  if(deq.size()>0){
    deque<ll> deq4=deq;
    vector<ll> D=A;
    D.push_back(deq4.back());
    deq4.pop_back();
    MAX=max(MAX,dfs(deq4,D,cnt,K));
    deque<ll> deq5=deq;
    vector<ll> E=A;
    E.push_back(deq5.front());
    deq5.pop_front();
    MAX=max(MAX,dfs(deq5,E,cnt,K));
  }


  return MAX;
}

ll solve2(int N,int K,vector<ll> A){
  deque<ll> deq2;
  REP(i,N){
    deq2.push_back(A[i]);
  }

  vector<ll> EMPTY;
  return max(0ll,dfs(deq2,EMPTY,0,K));
}

int main()
{
  INT(N);
  INT(K);
  VEC(ll,A,N);
  cout << solve(N,K,A) << endl;
  // cout << solve2(N,K,A) << endl;
  random_device seed_gen;
  mt19937_64 engine(seed_gen());
  while(0){
    ll N=engine()%(ll)10+1;
    ll K=engine()%(ll)3+1;
    vector<ll> A;
    REP(i,N){
      ll x=engine()%(ll)2e7+1-(ll)1e7;
      A.push_back(x);
    }
    cout << "checking input : " << N << " " << K << endl;
    REP(i,N){
      cout << A[i] << " ";
    }
    cout << endl;
    ll sol1=solve(N,K,A);
    ll sol2=solve2(N,K,A);
    if(sol1==sol2){
      cout << "OK" << endl;
    }else{
      cout << "NG" << endl;
      cout << "solver1 " << sol1 << endl;
      cout << "solver2 " << sol2 << endl;
      break;
    }
  }
}