#include <bits/stdc++.h>

using namespace std;


#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),v).end()

#define PB(a) push_back(a)
#define MOD 1000000007

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;cin>>n;
  for(int i=0;i<n;i++){
      int f=0,s=0,t=0,out=0,point=0;
      string st;
      while(cin>>st){
          if(st=="HIT"){
              if(t) point++;
              if(s) t=1;
              if(f) s=1;
              f=1;
          }
          else if(st=="HOMERUN"){
              point+=(f+s+t+1);
              f=0;s=0;t=0;
          }
          else{
              out++;
              if(out==3){
                  cout<<point<<endl;
                  break;
              }
          }
      }
  }
  
}