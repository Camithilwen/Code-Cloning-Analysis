#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

template<typename T>
T power(T x, long long n){
    if(n == 0) return 1;
    if(n == 1) return x;
    T tmp = power(x, n/2);
    if(n%2 == 0) return tmp * tmp;
    else return tmp * tmp * x;
}

ll N, M, D;
double ans = 0;
double f(double N, double D){
    if(D == 0) return N;
    else return (N-D)*2;
}

signed main(){
    cin >> N >> M >> D;
    ans = (double)(M-1)*f(N,D)/N/N;
    cout << fixed << setprecision(16) << ans << endl;
}