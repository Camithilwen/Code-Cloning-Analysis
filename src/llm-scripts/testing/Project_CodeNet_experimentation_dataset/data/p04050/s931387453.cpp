#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll N,M;
vector<int> A;

int main(){
  cin>>N>>M;
  A.resize(M);
  rep(i,M)cin>>A[i];
  if(M==1){
    cout<<A[0]<<endl;
    if(A[0]>1){
      cout<<2<<endl;
      cout<<A[0]-1<<" "<<1<<endl;
    }else{
      cout<<1<<endl;
      cout<<1<<endl;
    }
    return 0;
  }
  vector<int> os;
  rep(i,M){
    if(A[i]%2==1)os.push_back(i);
  }
  if(os.size()>2){
    cout<<"Impossible"<<endl;
    return 0;
  }
  if(os.size()==1){
    swap(A[0],A[os[0]]);
  }else if(os.size()==2){
    swap(A[0],A[os[0]]);
    swap(A[M-1],A[os[1]]);
  }
  rep(i,M)cout<<A[i]<<" ";
  cout<<endl;
  if(A[0]-1>0){
    cout<<M<<endl;
    cout<<A[0]-1<<" ";
  }else{
    cout<<M-1<<endl;
  }
  repl(i,1,M-1)cout<<A[i]<<" ";
  cout<<A[M-1]+1<<endl;
  return 0;
}
