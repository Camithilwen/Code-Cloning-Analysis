#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;//998'244'353;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

template<typename T>
T power(T x, long long n, const T &m){
    if(n == 0) return 1;
    if(n == 1) return x;
    T tmp = power(x, n/2, m);
    if(n%2 == 0) return tmp * tmp % m;
    else return tmp * tmp % m * x % m;
}

template<typename T>
T inverse(T x, const T &m){
    return power(x, m-2, m);
}

struct Combination{
    int N;
    long long M;
    vector<long long> f, i;
    void init(int n, long long m){
        N = n; M = m;
        f.resize(N+1); f[0] = 1;
        i.resize(N+1); i[0] = 1;
        for(long long j=1; j<=N; j++){
            f[j] = f[j-1]*j%M;
            i[j] = inverse(f[j], M);
        }
    }
    long long fact(int n){
        return f[n];
    }
    long long C(int n, int r){
        return f[n] * i[r] % M * i[n-r] % M;
    }
};

int N;
ll M;

Combination comb;

ll solve(int N){
    ll ans = 0;
    ll tmp = 1;
    rep(i, N/3+1){
        ans += tmp * comb.i[i];
        ans %= M;
        if(i == N/3) continue;
        tmp *= comb.C(N-2*i, 2);
        tmp %= M;
    }
    return ans;
}

signed main(){
    cin >> N >> M;
    comb.init(3*N, M);
    ll ans = 0;
    ll tmp = 1;
    rep(i, N+1){
        ans += solve(3*(N-i)) * tmp % M * comb.i[i];
        ans %= M;
        if(i == N) continue;
        tmp *= comb.C(3*(N-i), 3) * 2;
        tmp %= M;
    }
    cout << ans << endl;
}