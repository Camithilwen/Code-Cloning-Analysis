#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int N; cin>>N;
  vi A(N);
  rep(i,0,N) cin>>A[i];
  int ans=0;
  map<int,int,greater<int>> M;
  rep(i,0,N) M[A[i]]++;
  for(auto p:M){
    int X=p.first;
    REP(i,1,60){
      int P=(1ll<<60-i);
      if(M.count(P-X)){
        if(P-X==X){
          ans+=M[X]/2;
          M[X]%=2;
        }
        else{
          int Q=min(M[P-X],M[X]);
          ans+=Q;
          M[P-X]-=Q;
          M[X]-=Q;
        }
      }
    }
  }
  cout<<ans<<endl;
  }

