#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
#define pii pair<int, int>
#define pll pair<ll, ll>
typedef long long ll;
typedef double lf;
typedef long long ll;
// const int mod = 1000000007;
const int mod = 998244353;

// vector<string> Qs(max_n);

bool check(vector<pll> ps){
    ll h = 0;
    for(auto p:ps){
        ll b = h + p.first;
        if(b < 0) return false;
        h = h + p.second;
    }

    return true;
}

void Main(){
    ll N;
    string s;
    sll(N);
    vector<pll> ls, rs;
    ll total = 0;
    rep(i, N){
        cin >> s;
        ll h = 0, b = 0;
        for(auto c:s){
            if(c=='(') h++; else h--;
            b = min(b, h);
        }
        if(h>=0) ls.emplace_back(b, h);
        else rs.emplace_back(b-h, -h);
        total += h;
    }
    sort(ls.rbegin(), ls.rend());
    sort(rs.rbegin(), rs.rend());

    if(check(ls) && check(rs) && total == 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    

}

int main(){
    Main();

    return 0;

}