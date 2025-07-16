#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
*/

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

using Graph = vector<vector<int>>;

ll calc(ll a, ll b, ll p){//aのb乗をpで割った余り
  if(b == 0) return 1;

  else if(b%2 == 0){
    ll d = calc(a,b/2,p);
    return (d*d)%p;
  }
  else if(b%2 == 1){
    return (a * calc(a,b-1,p))%p;
  }
}

typedef pair<int,int> P;

bool is_prime(int n){//nが素数であるかどうか判定 iで割り切れると素数でない
    if(n == 1) return false;//1は例外
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0) return false;
    }
    
    return true;
}
int factorial(int a){
  int res = 1;
  while(a){
    res *= a;
    a--;
  }
  return res;
}

//r本再利用されない時、N本から再利用して売れる本数
int rec(int m,int n,int N,int r){
  if(N == 0) return 0;

  int k = N/m * n;//新たに作り出す本数
  r = N%m;//再利用されない本数
  int res = N + k;//売った本数
  
  while(1){
    k = k/m * n;//k本からk/m本再利用
    res += k;
    r += k%m;
    if(k < m){//k本で再利用できなくなったら
      k += r;
      res += rec(m,n,k,r);
    }
  }
}

int main(){
  int X,Y;
  cin >> X >> Y;
  if(X == 1 && Y == 1) cout << 1000000 << endl;
  else if((X == 1 && Y == 2) || X == 2 && Y == 1) cout << 500000 << endl;
  else if((X == 1 && Y == 3) || X == 3 && Y == 1) cout << 400000 << endl;
  else if(X == 2 && Y == 2) cout << 400000 << endl;
  else if((X == 2 && Y == 3) || (X == 3 && Y == 2)) cout << 300000 << endl;
  else if(X == 3 && Y == 3) cout << 200000 << endl;
  else if(X == 1 || Y == 1) cout << 300000 << endl;
  else if(X == 2 || Y == 2) cout << 200000 << endl;
  else if(X == 3 || Y == 3) cout << 100000 << endl;
  else cout << 0 << endl;
}
