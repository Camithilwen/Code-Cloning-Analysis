#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const long long INF = 1<<29;

const int MOD = 1000000007;
long long ruizyou(long long m,long long n){
  if(m == 0)return 0;
  if(m == 1)return 1;
  long long ans = 1;
  long long tmp = m;
  for(int i=0;i<=30;i++){
    if(n & (1<<i)){
      ans *= tmp;
      ans %= MOD;
    }
    tmp *= tmp;
    tmp %= MOD;
  }
  return ans;
}
long long kaizyou(long long x){
  if(x == 0)return 1;
  return x * kaizyou(x-1) % MOD;
}
long long comb(long long x,long long y){
  long long bunsi = kaizyou(x);
  long long bunbo = kaizyou(x-y) * kaizyou(y) % MOD;
  return bunsi * ruizyou((int)bunbo,MOD-2) % MOD;
}
struct unionfind{
  vector<int> par;
  vector<int> hukasa;
  unionfind(int n){
    par = vector<int>(n);
    hukasa = vector<int>(n,0);
    for(int i=0;i<n;i++){
      par.at(i) = i;
    }
  }
  int root(int x){
    if(par.at(x) == x)return x;
    return root(par.at(x));
  }
  void unite(int x,int y){
    int rx = root(x);
    int ry = root(y);
    if(rx == ry)return;
    if(hukasa.at(rx) >= hukasa.at(ry)){
      par.at(ry) = rx;
      hukasa.at(rx) = max(hukasa.at(ry) + 1,hukasa.at(rx));
    }
    else{
      par.at(rx) = ry;
    }
  }
  bool same(int x,int y){
    return root(x) == root(y);
  }
};


int main(){
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<int>> lr(m,vector<int>(2));
  for(int i=0;i<m;i++){
    cin >> lr.at(i).at(0) >> lr.at(i).at(1);
    lr.at(i).at(0)--;lr.at(i).at(1)--;
  }
  vector<vector<int>> pq(q,vector<int>(2));
  for(int i=0;i<q;i++){
    cin >> pq.at(i).at(0) >> pq.at(i).at(1);
    pq.at(i).at(0)--;pq.at(i).at(1)--;
  }
  vector<vector<int>> table(n,vector<int>(n,0));
  for(int i=0;i<m;i++){
    table.at(lr.at(i).at(0)).at(lr.at(i).at(1))++;
  }
  vector<vector<int>> s(n,vector<int>(n));
  s[0][0] = table[0][0];
  for(int i=1;i<n;i++){
    s[i][0] = s[i-1][0] + table[i][0];
    s[0][i] = s[0][i-1] + table[0][i];
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + table[i][j];
    }
  }
  for(int i=0;i<q;i++){
    int pp = pq.at(i).at(0),qq = pq.at(i).at(1);
    if(pp == 0)cout << s[qq][qq] << endl;
    else{
      cout << s[qq][qq] - s[qq][pp-1] - s[pp-1][qq] + s[pp-1][pp-1] << endl;
    }
  }
}