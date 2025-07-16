#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N;
    cin >> N;
    map<ll, ll> A;
    rep(i, N) {
        ll tmp;
        cin >> tmp;
        A[tmp]++;
    }

    vl st;
    for (auto x : A) {
        int y = x.second;
        while (y >= 2) {
            y -= 2;
            st.push_back(x.first);
        }
    }

    if (st.size() < 2) {
        cout << 0 << endl;
    } else {
        sort(st.begin(), st.end());
        reverse(st.begin(), st.end());

        ll ans = st[0] * st[1];

        cout << ans << endl;
    }
}