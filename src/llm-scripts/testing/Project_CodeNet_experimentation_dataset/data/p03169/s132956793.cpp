#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll N;

//dp
vector<vector<vector<double>>> table;

double dp(ll i,ll j,ll k){
  //cout<<i<<" "<<j<<" "<<k<<endl;
  if(i==0&&j==0&&k==0) return 0;
  if(table.at(i).at(j).at(k)>-1) return table.at(i).at(j).at(k);
  
  table.at(i).at(j).at(k)=0;
  if(i>0) table.at(i).at(j).at(k)+=dp(i-1,j,k)*i/N;
  if(j>0) table.at(i).at(j).at(k)+=dp(i+1,j-1,k)*j/N;
  if(k>0) table.at(i).at(j).at(k)+=dp(i,j+1,k-1)*k/N;
  table.at(i).at(j).at(k)+=1;
  
  return table.at(i).at(j).at(k)/=(double)(i+j+k)/N;
}

int main()
{
  cin>>N;
  vector<ll> vec(4,0); rep(i,N) {ll a; cin>>a; vec.at(a)++;}
  
  //dp
  table=vector<vector<vector<double>>>(N+1,vector<vector<double>>(N+1,vector<double>(N+1,-1)));
  
  cout<<fixed<<setprecision(15)<<dp(vec.at(1),vec.at(2),vec.at(3))<<endl;
  /*
  rep(i,2) {
    if(i!=0) cout<<" ";
    cout<<table.at(0).at(0).at(i);
  }
  cout<<fixed<<setprecision(15)<<endl;
  */
  
  
  return 0;
}