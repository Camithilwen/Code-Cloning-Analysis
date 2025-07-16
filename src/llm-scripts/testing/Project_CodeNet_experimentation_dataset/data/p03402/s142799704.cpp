#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

void printString(vector<string>& ans){
    ll h = ans.size(), w = ans[0].size();
    cout << h << " " << w << endl;
    rep(i, h) cout << ans[i] << endl;
}

int main(){
    Init();
    ll a, b; cin >> a >> b;
    string wb = string(100, '.');
    string bw = string(100, '#');
    vector<string> ans;
    for(ll i=1; i<100; i+=2){
        wb[i] = '#';
        bw[i] = '.';
    }

    a--; b--;
    ll bh = ((ll)ceil(b/50.0));
    ll wh = ((ll)ceil(a/50.0));

    // □■□■□■...□■
    // □□□□□□...□□　で白1個に対して黒50個おける。（20行あれば500個おける。）
    rep(i, bh){
        if(i == bh-1){
            if(b%50 != 0) ans.emplace_back(wb.substr(0, (b%50)*2+1) + string(100-((b%50)*2+1), '.'));
            else ans.emplace_back(wb);
        }
        else{
            ans.emplace_back(wb);
            ans.emplace_back(string(100, '.'));
        }
    }
    // □□□□□□...□□
    // ■■■■■■...■■　を境界に置く。
    ans.emplace_back(string(100, '.'));
    ans.emplace_back(string(100, '#'));

    // ■□■□■□...■□
    // ■■■■■■...■■　で黒1個に対して白50個おける。（20行あれば500個おける。）
    rep(i, wh){
        if(i == wh-1){
            if(a%50 != 0) ans.emplace_back(bw.substr(0, (a%50)*2+1) + string(100-((a%50)*2+1), '#'));
            else ans.emplace_back(bw);
        }
        else{
            ans.emplace_back(bw);
            ans.emplace_back(string(100, '#'));
        }
    }

    printString(ans);
}