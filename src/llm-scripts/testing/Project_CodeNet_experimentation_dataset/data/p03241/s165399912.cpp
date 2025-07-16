#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
struct PrimeNumber
{
    //O(sqrt(n))
    //sosu hantei
    bool is_prime(long long n){
        for(long long i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return n != 1;
    }

    //O(sqrt(n))  isn't sorted
    //yakusu rekkyo
    vector<long long> divisor(long long n){
        vector<long long> res;
        for(long long i = 1; i * i <= n; i++){
            if(n % i == 0){
                res.push_back(i);
                if(i != n / i) res.push_back(n / i);
            }
        }
        return res;
    }

    //O(sqrt(n))
    //soinsu bunkai
    map<long long, long long> prime_factor(long long n){
        map<long long, long long> res;
        for(long long i = 2; i * i <= n; i++){
            while(n % i == 0){
                n /= i;
                res[i]++;
            }
        }
        if(n != 1) res[n] = 1;
        return res;
    }

    //O(n log log n)
    //n madeno sosu rekkyo
    vector<long long> eratosthenes(long long n){
        vector<long long> prime;
        vector<bool> is_prime(n + 1, true);
        long long p = 0;
        is_prime[0] = false; is_prime[1] = false;
        for(long long i = 2; i <= n; i++){
            if(is_prime[i]) prime.push_back(i);
            for(long long j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
        return prime;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    ll ans = 1;
    PrimeNumber p;
    vector<ll> vec = p.divisor(m);
    rep(i, vec.size()){
        ll d = m / vec[i];
        if(d >= n) ans = max(ans, vec[i]);
    }
    cout << ans << endl;
}