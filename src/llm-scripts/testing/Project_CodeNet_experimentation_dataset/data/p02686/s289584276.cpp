#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

// ref : https://atcoder.jp/contests/abc167/submissions/13086967

int main(){
    int n;
    cin >> n;
    vector<P> pos, neg;

    rep(i, n){
        string s;
        cin >> s;
        int tmp = 0, mn = 0;
        for(char c : s){
            if (c == '(') tmp++;
            else tmp--;
            mn = min(mn, tmp);
        }
        if (tmp >= 0) pos.push_back({mn, tmp});
        else neg.push_back({mn, tmp});
    }
    sort(pos.rbegin(), pos.rend());

    int tot = 0;

    for (auto p : pos){
        if (tot + p.first < 0) {
            cout << "No" << endl;
            return 0;
        }
        tot += p.second;
    }

    sort(neg.begin(), neg.end(), [](auto a, auto b){ return a.second - a.first > b.second - b.first; } ); // sum - mnが大きい順にソートする

    for(auto& p : neg){
        if(tot + p.first < 0){
            cout << "No" << endl;
            return 0;
        }
        tot += p.second;
    }
 
    if(tot != 0){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}
