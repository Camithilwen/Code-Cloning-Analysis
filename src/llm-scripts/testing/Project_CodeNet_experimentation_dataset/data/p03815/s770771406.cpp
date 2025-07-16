#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    ll x; cin >> x;
    ll ans = x/11; 
    int r = x % 11;
    int add = 0;
    if(r > 0) add = 1;
    if(r > 6) add = 2;
    cout << ans * 2 + add << endl;
}