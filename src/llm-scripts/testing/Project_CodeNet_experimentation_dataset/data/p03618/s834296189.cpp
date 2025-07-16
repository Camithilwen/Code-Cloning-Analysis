#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    string s;
    cin >> s;

    map<int, int> num;
    ll ans = 0;
    rep(i, s.size()){
        if (num.find(s[i]-'a') == num.end()){
            num.insert({s[i]-'a', 1});
        } else {
            num[s[i]-'a']++;
        }
        ans += i+1-num[s[i]-'a'];
    }
    cout << ans+1 << endl;
}
