#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 int H, W;
 bool seen[10000][10000];
 char S[10000][10000];
 int dx[4] = {1, -1, 0, 0};
 int dy[4] = {0, 0, 1, -1};
vector<pair<ll, ll>> prime_factorize(ll n) { //素因数分解と各素数の個数
    vector<pair<ll, ll>> res;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
        {
            continue;
        }
        int num = 0;
        
        while (n % i == 0)
        {
            ++num;
            n /= i;
        }
        res.push_back(make_pair(i, num));
       
    }
     if (n != 1) 
        {
            res.push_back(make_pair(n, 1));
        }
        return res;
        
} 
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void dfs(int st, int fi) {
  //  cout << st << " " << fi <<  endl;
    if (st < 0 || fi < 0 || st >= H || fi >= W)
    {
        return ;
    }
    if (S[st][fi] == '#')
    {
        return ;
    }

    if (seen[st][fi] == 1)
    {
        return ;
    }
    
    
    if (S[st][fi] == '.')
    {
        seen[st][fi] = 1;
    }
    

    dfs(st + 1, fi);
    dfs(st, fi + 1);
    dfs(st, fi - 1);
    dfs(st - 1, fi);
    
}
int main() {
    ll N, T;
    cin >> N >> T;
    vector<ll> t(N);

    for(int i = 0; i < N; i++) cin >> t[i];

    ll ans = 0;

    for(int i = 0; i < N - 1; i++) {
        if(t[i] + T <= t[i + 1]) ans += T;
        else {
            ans += (t[i + 1] - t[i]);
        }
    }
    ans += T;

    cout << ans << endl;


 return 0;
}
