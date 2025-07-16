#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int T,A,n;
  cin >> n >> T >> A;
  T--,A--;
  vector<vector<int>> v(n);
  rep(i,n-1){
    int a,b;cin >> a >> b;
    a--,b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  ll res = 0;
  bool is = true;
  vector<int> next(n,T);
  {
    vector<int> dt(n,-1);
    dt[T] = 0;
    queue<int> que;
    que.push(T);
    while(!que.empty()){
      int ov = que.front();que.pop();
      for(int nv : v[ov]){
        if(dt[nv] != -1)continue;
        next[nv] = ov;
        dt[nv] = dt[ov] + 1;
        que.push(nv);
      }
    }
    if(dt[A] & 1){
      int d = dt[A];
      while(dt[next[A]] >= d-d/2)A = next[A];
      T = A;
      while(dt[next[T]] >= d/2 && next[T] != T)T = next[T];
      res += d/2;
    }else{
      int d = dt[A];
      while(dt[next[A]] >= d-(d-2)/2)A = next[A];
      T = A;
      while(dt[next[T]] >= (d-2)/2 && next[T] != T)T = next[T];
      res += (d-2)/2;
      is = false;
    }
  }
  int L = -1;
  {
    for(int ov : v[T])for(int nv : v[ov])if(nv == A){
      L = ov;
      break;
    }
  }
  queue<int> que;
  que.push(T);
  vector<int> d(n,-1);
  d[T] = 0;
  while(!que.empty()){
    int ov = que.front();que.pop();
    for(int nv : v[ov]){
      if(nv == A || d[nv] != -1 || nv == L)continue;
      d[nv] = d[ov]+1;
      que.push(nv);
    }
  }
  int K = T;
  rep(i,n)if(d[i] > d[K])K = i;
  if(is)res += d[K];
  else res += d[K]+1;
  cout << res << endl;

  /*////////////
  cout << "L :" << L << endl;
  printf("T :%d A :%d\n",T+1,A+1);

  */////////////


  return 0;
}
/*
7
4 7
1 2
1 3
2 4
2 5
3 6
3 7
*/