#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

bool check(string s, vector<char> &res, char c1, char c2) {
    res[0] = c1, res[1] = c2;
    int n = s.size();
    for(int i = 1; i < s.size() - 1; i++) {
        if(s[i] == 'o' && res[i] == 'S')
            res[i + 1] = res[i - 1];
        else if(s[i] == 'o' && res[i] == 'W')
            res[i + 1] = (res[i - 1] == 'W' ? 'S' : 'W');
        else if(s[i] == 'x' && res[i] == 'S')
            res[i + 1] = (res[i - 1] == 'W' ? 'S' : 'W');
        else if(s[i] == 'x' && res[i] == 'W')
            res[i + 1] = res[i - 1];
    }
    bool ret = false;
    if((res[0] == 'W' && s[0] == 'o') || (res[0] == 'S' && s[0] == 'x')) {
        ret = !(res[1] == res[s.size() - 1]);
        if((res[n - 1] == 'W' && s[n - 1] == 'o') ||
           (res[n - 1] == 'S' && s[n - 1] == 'x')) {
            ret &= !(res[0] == res[n - 2]);
        } else {
            ret &= (res[0] == res[n - 2]);
        }
        return ret;
    } else {
        ret = (res[1] == res[s.size() - 1]);
        if((res[n - 1] == 'W' && s[n - 1] == 'o') ||
           (res[n - 1] == 'S' && s[n - 1] == 'x')) {
            ret &= !(res[0] == res[n - 2]);
        } else {
            ret &= (res[0] == res[n - 2]);
        }
        return ret;
    }
}

int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;
    vector<char> res(N);
    if(check(s, res, 'S', 'S')) {
        rep(i, N) cout << res[i];
        cout << endl;
        return 0;
    }
    if(check(s, res, 'S', 'W')) {
        rep(i, N) cout << res[i];
        cout << endl;
        return 0;
    }
    if(check(s, res, 'W', 'S')) {
        rep(i, N) cout << res[i];
        cout << endl;
        return 0;
    }
    if(check(s, res, 'W', 'W')) {
        rep(i, N) cout << res[i];
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}