#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

const string YES = "Yes";
const string NO = "No";

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> up, down;
    REP(i, n){
        ll cur = 0, bottom = 0;
        string s;
        cin >> s;
        for(char c : s){
            if(c == '('){
                cur++;
            }else{
                cur--;
            }
            bottom = min(cur, bottom);
        }
        if(cur >= 0){
            up.emplace_back(bottom, cur);
        }else{
            down.emplace_back(bottom - cur, - cur);
        }
    }

    sort(up.rbegin(), up.rend());
    ll cur_up = 0;
    for(auto p : up){
        ll btm = p.first;
        if(cur_up + btm < 0){
            cout << NO << endl;
            return 0;
        }
        cur_up += p.second;
    }

    sort(down.rbegin(), down.rend());
    ll cur_down = 0;
    for(auto p : down){
        ll btm = p.first;
        if(cur_down + btm < 0){
            cout << NO << endl;
            return 0;
        }
        cur_down += p.second;
    }

    if(cur_up != cur_down){
        cout << NO << endl;
    }else{
        cout << YES << endl;
    }
    return 0;
}
