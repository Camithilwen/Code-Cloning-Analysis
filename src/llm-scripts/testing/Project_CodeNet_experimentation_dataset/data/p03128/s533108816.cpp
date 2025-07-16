#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

const int match[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string str[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

string dp[10][10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i = 0; i < m; ++i) {
        cin >> v[i];

    }
    sort(all(v), greater<int>());

    for(int i = 0; i < m; ++i) {
        int mvi = match[v[i]];
        for(int j = 1; j <= n; ++j) {
            if(i == 0) {
                if(j % mvi == 0) {
                    dp[i][j] = dp[i][j - mvi];
                    dp[i][j] += str[v[i]];

                }
            } else {
                string s1 = dp[i - 1][j];
                string s2;
                if(j % mvi == 0 || (j >= mvi && dp[i][j - mvi].size() != 0)) {
                    s2 = dp[i][j - mvi];
                    s2 += str[v[i]];

                }
                if(s1 == s2 && s1.size() == 0) {
                    continue;

                }
                if(s2.size() == 0) dp[i][j] = s1;
                else {
                    if(s1.size() < s2.size()) {
                        dp[i][j] = s2;

                    } else if(s1.size() > s2.size()){
                        dp[i][j] = s1;

                    } else {
                        if(s1 < s2) {
                            dp[i][j] = s2;

                        } else {
                            dp[i][j] = s1;

                        }
                    }
                }
            }
        }
    }
    cout << dp[m - 1][n] << endl;
    return 0;
}

