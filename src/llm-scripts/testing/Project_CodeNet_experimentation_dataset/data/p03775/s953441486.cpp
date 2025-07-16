#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const ll INFL = 1e18;
const ll mod = 1e9 + 7;
 
int digit(ll x) {
    int digits = 0;

    while(x > 0){
        x /= 10;
        digits++;
    }

    return digits;
}
 
ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

bool is_prime(long long N){
    if (N == 1) return false;
    for (long long i = 2;i * i <= N;i++){
        if (N % i == 0) return false;
    }
    return true;
}
 
ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}
 
double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
 
///////////////////////////////////////////////////////////////////////////////////

int main(){
    long long n;
    cin >> n;
    int ans = digit(n);
    for (long long i = 1LL;i * i <= n;i++){
        if (n % i != 0) continue;
        long long b = n / i;

        int res = max(digit(i), digit(b));

        if (ans > res){
            ans = res;
        }
    }

    cout << ans << endl;
}