#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
//#include <unistd.h>
//#include <stdio.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll INF = 1LL << 60;
const ll mod = 1000000007;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}

long long fac[51000], finv[51000], inv[51000];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 51000; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
/*
int main() {
    // 前処理
    COMinit();

    // 計算例
    cout << COM(100000, 50000) << endl;
}*/

//printf("%.10f\n", N);
/*
ll fibo(ll n){
    if(memo[n] != 0)return memo[n];
    if(n <= 1)return n;
    else return memo[n] = fibo(n - 1)+ fibo(n - 2);
}*/
/*  vector<ll> vec = {1,2,5,6,8,9,10};
    cout << binary_search(all(vec),5) << endl; -> true*/
/*
    vector<ll> vec = {1,2,5,6,8,9,10};
    auto n = upper_bound(all(vec),4);
    cout << *n << endl; -> 5*/
/*
    cout << fixed << setprecision(15);
*/

int main(){
    ll H,W;
    cin >> H >> W;
    vector<vector<char>> maze(H,vector<char>(W));
    queue<P> que;
    vector<vector<ll>> d(H,vector<ll>(W,INF));
    rep(i,H){
        rep(j,W){
            cin >> maze[i][j];
            if(maze[i][j] == '#'){
                que.push(P(i,j));
                d[i][j] = 0;
            }
        }
    }
    const ll dx[] = {1,0,0,-1};
    const ll dy[] = {0,1,-1,0};
    while(que.size()){
        P p = que.front();que.pop();
        rep(i,4){
            ll hx = dx[i] + p.first;
            ll hy = dy[i] + p.second;
            if(hx >= 0 && hy >= 0 && hx < H && hy < W && d[hx][hy] == INF){
                que.push(P(hx,hy));
                d[hx][hy] = d[p.first][p.second] + 1;
            }
        }
        //cout << p.first << " " << p.second << endl;
    }
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            ans = max(d[i][j],ans);
        }
    }
    cout << ans << endl;
}