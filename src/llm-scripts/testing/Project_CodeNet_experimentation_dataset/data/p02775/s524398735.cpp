//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    reverse(all(s));
    s += '0';

    rep(i, n+1) {
        if(s[i] >= 6+'0' || s[i] == 5+'0' && s[i+1] >= 5+'0') {
            ans += 10-s[i]+'0';
            while(s[++i] == '9');
            ++s[i--];
        } else {
            ans += s[i] - '0';
        }
    }

    cout << ans << endl;
}