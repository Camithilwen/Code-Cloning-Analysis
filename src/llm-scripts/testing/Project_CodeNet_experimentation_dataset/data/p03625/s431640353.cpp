#include <bits/stdc++.h>
using namespace std;
//typedef int64_t int;
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise cout.precision(10); cout << fixed;
#define pb push_back
#define mk make_pair
#define endl "\n"
#define int int64_t
#define ll long long
const ll Inf = 1e9 + 7;
int n, k;


void solve() {
    int n, co = 0;
    cin >> n;
    std::map<int, int> mp;
    std::vector<int> num;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        //cout << mp[x] << " ";
        if (mp[x] % 2 == 0 && mp[x] != 0) {
            num.pb(x);
            //cout << "xx" << endl;
        }
    } sort(all(num), greater<int>());
    if (num.size() < 2) {
        cout << 0 << endl;
    } else {
        cout << num[0]*num[1] << endl;
    }

}
int32_t main()
{
    fastio;
    precise;

    //int test; cin >> test; while (test--)
    solve();
    return 0;
}
