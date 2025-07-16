#include <bits/stdc++.h>
#include <set>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const long long INF = 1<<29;

const int MOD = 998244353;
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
  return bunsi * ruizyou(bunbo,MOD-2) % MOD;
}
struct unionfind{
  vector<int> par;
  vector<vector<int>> children;
  vector<int> hukasa;
  vector<int> kazu;
  unionfind(int n){
    par = vector<int>(n);
    hukasa = vector<int>(n,0);
    kazu = vector<int>(n,1);
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
      kazu.at(rx) += kazu.at(ry);
    }
    else{
      par.at(rx) = ry;
      kazu.at(ry) += kazu.at(rx);
    }
  }
  void newkazu(){
    int n = kazu.size();
    for(int i=0;i<n;i++){
      kazu.at(i) = kazu.at(root(i));
    }
  }
  bool same(int x,int y){
    return root(x) == root(y);
  }
};
int ctoi(char a){
  return a - '0';
}
long long gcd(long long a,long long b){
  long long c = max(a,b);
  long long d = min(a,b);
  if(d % c == 0)return c;
  return gcd(c,d%c);
}
long long lcm(long long a,long long b){
  return a * b / gcd(a,b);
}
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)cin >> s.at(i).at(j);
  }
  vector<vector<int>> table(h,vector<int>(w,-1));
  queue<pii> q;
  q.push(pii(0,0));
  table.at(0).at(0) = 1;
  bool flag = false;
  int count;
  while(!q.empty()){
    pii tmppair = q.front();
    q.pop();
    int x,y;
    tie(x,y) = tmppair;
    set<pii> se;
    if(x-1 >= 0)se.insert(pii(x-1,y));
    if(x+1 < h)se.insert(pii(x+1,y));
    if(y-1 >= 0)se.insert(pii(x,y-1));
    if(y+1 < w)se.insert(pii(x,y+1));
    for(auto t:se){
      int tx,ty;
      tie(tx,ty) = t;
      if(s.at(tx).at(ty) == '.' && table.at(tx).at(ty) == -1){
        table.at(tx).at(ty) = table.at(x).at(y) + 1;
        q.push(t);
      }
      if(t == pii(h-1,w-1)){
        count = table.at(tx).at(ty);
        flag = true;
        break;
      }
    }
    if(flag) break;
  }
  if(!flag) cout << -1 << endl;
  else{
    int count2 = 0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(s.at(i).at(j) == '#')count2++;
      }
    }
    cout << h * w - count - count2 << endl;
  }
}