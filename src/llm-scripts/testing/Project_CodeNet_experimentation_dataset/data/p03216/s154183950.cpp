#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;
#define int long long
const int mod = 1e9 + 7;

const int N = 1e6 + 5;

int n, q, sum[N], total[N], ways;

string s;
bool used[N];
vector<int> vec;

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    s = "+" + s;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'M')
            sum[i] = 1;
        sum[i] += sum[i - 1];
        if(s[i] == 'C')
            total[i] = 1;
        total[i] += total[i - 1];
        if(s[i] == 'D')
            vec.pb(i);
    }
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        if(vec.size() == 0) {
            cout << "0\n";
            continue;
        }
        ways = 0;
        long long sumb = 0, sumc = 0;
        int l = vec[0], r = l;
        for(int i = 0; i < vec.size(); i++) {
            while(l < vec[i]) {
                if(s[l] == 'C')
                    sumc--;
                if(s[l] == 'M')
                    sumb -= sumc;
                l++;
            }
            while(r - l < k && r <= n) {
                if(s[r] == 'C') {
                    sumb += sum[r] - sum[l - 1];
                    sumc++;
                }
                r++;
            }
            ways += sumb;
            //cout << l << " " << r << " " << sumb << "\n";
        }
        cout << ways << "\n";
    }
}

