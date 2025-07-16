#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

vector<pair<ll, ll> > prime; 

void prime_fuct(ll x){
    for (ll i = 2; i * i <= x; i++){
        if(x % i == 0){
            pair<ll, ll> p = make_pair(i, 0);
            while (x % i == 0){
                x /= i;
                p.second++;
            }
            prime.push_back(p);
        }
    }
    if(x > 1){
        pair<ll, ll> p = make_pair(x, 1);
        prime.push_back(p);
    }
}

ll gcd(ll  x, ll y){
    if(y == 0) return x;
    else  return gcd(y, x % y);
}




int main(){
    ll a, b;
    cin >> a >> b;
    ll n = gcd(a, b);
    prime_fuct(n);
    ll ans = (ll)prime.size() + 1;
    cout << ans << endl;
}