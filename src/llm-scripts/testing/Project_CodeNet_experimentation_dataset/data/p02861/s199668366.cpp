#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  double n;
  cin>>n;
  vector<vector<double>> d(n,vector<double>(2));
  rep(i,n)rep(j,2) cin>>d[i][j];
  vector<int> t(n);
  rep(i,n) t[i]=i;
  double sum=0;
  int cnt=0;
  do{
    for(int i=1;i<n;i++){
      sum+=sqrt((d[t[i]][0]-d[t[i-1]][0])*(d[t[i]][0]-d[t[i-1]][0])+(d[t[i]][1]-d[t[i-1]][1])*(d[t[i]][1]-d[t[i-1]][1]));
    }
    cnt++;
  }while(next_permutation(all(t)));
  printf("%.10f\n",sum/cnt);
}