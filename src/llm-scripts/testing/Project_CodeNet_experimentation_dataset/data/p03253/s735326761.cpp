#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>

//#define INF 100000000
//#define MOD (int) (1e9+7)
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        //そのまま計算すると負の値になるのでMODを足す
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

int main(){
    long long int n, m;
    cin >> n >> m;

    if(m == 1){
        //全部1の1通りしかありえない
        cout << 1 << endl;
        return 0;
    }

    long long int i;
    map<long long int, long long int> prime;

    //素因数分解
    long long int tmp = m;
    for(i = 2; i * i <= m; i++){
        long long int count = 0;
        while(tmp%i == 0){
            tmp /= i;
            count++;
        }
        prime[i] = count;
    }
    if(tmp*tmp > m) prime[tmp] += 1;

    COMinit();
    long long int ans = 1;
    for(auto itr = prime.begin(); itr != prime.end(); itr++){
        long long int val = itr->second;
        ans = (ans * COM(n+val-1, val))%MOD;
    }

    cout << ans << endl;
}
