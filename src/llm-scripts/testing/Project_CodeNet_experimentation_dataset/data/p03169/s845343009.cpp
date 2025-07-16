#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 300

// dp[i][j][k]:1スi枚,2スj枚,3スk枚
double dp[MAXN+1][MAXN+1][MAXN+1];
int n;

double rec(int i, int j, int k){
  if(!i && !j && !k)return 0.0;
  if(dp[i][j][k]>0.0)return dp[i][j][k];

  double sum = i+j+k;
  double ret = n/sum;
  if(i>0)ret += (double)(i/sum) * rec(i-1, j, k);
  if(j>0)ret += (double)(j/sum) * rec(i+1, j-1, k);
  if(k>0)ret += (double)(k/sum) * rec(i, j+1, k-1);

  return dp[i][j][k]=ret;
}

int main(){
  cin>>n;
  double dn=(double)n;
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  map<int, int>m;
  for(auto t:a)m[t]++;

//  cout<<fixed<<setprecision(12)<<rec(m[1], m[2], m[3])<<endl;
  printf("%.12f", rec(m[1], m[2], m[3]));

  return 0;

rep(i, n)rep(j, n)rep(k, n)cout<<dp[i][j][k]<<' '<<i<<' '<<j<<' '<<k<<endl;

  return 0;
}