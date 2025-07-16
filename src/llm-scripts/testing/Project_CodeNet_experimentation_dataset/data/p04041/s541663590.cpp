#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()

const int mod = (int) 1e9 + 7;

int n;
int x, y, z;

map <vector<int>, int> mp;
vector<int> seq[205000];
int len[205000];
int seqSum[205000];
bool haiku[205000];
int cnt;
int mxSum = 0;
int mxNum = 0;

bool check(vector<int>& v) {
    int p = 0;
    int xx = x, yy = y, zz = z;
    while (p < sz(v) && xx > 0) {
        xx -= v[p];
        p++;
    }
    while (p < sz(v) && yy > 0) {
        yy -= v[p];
        p++;
    }
    while (p < sz(v) && zz > 0) {
        zz -= v[p];
        p++;
    }
    return xx == 0 && yy == 0 && zz == 0 && p == sz(v);
}

void go(vector<int>& v, int sum) {
    mp[v] = cnt;
    len[cnt] = sz(v);
    seq[cnt] = v;
    seqSum[cnt] = sum;
    haiku[cnt] = check(v);
    cnt++;

    for (int i = 1; i <= min(mxNum, mxSum - sum); i++) {
        v.push_back(i);
        go(v, sum + i);
        v.pop_back();
    }
}

long long dp[45][2][130500];
int mv[130500][12];

int main() {

    cin >> n >> x >> y >> z;
    mxSum = x + y + z;
    mxNum = max(max(x, y), z);

    vector<int> v;
    go(v, 0);

    // cerr << cnt << endl;

    for (int i = 0; i < cnt; i++) {
        for (int num = 1; num <= mxNum; num++) {
            int sum = seqSum[i] + num;
            int p = 0;
            while (p < sz(seq[i]) && sum > mxSum) {
                sum -= seq[i][p];
                p++;
            }
            vector<int> go;
            while (p < sz(seq[i])) {
                go.push_back(seq[i][p]);
                p++;
            }
            go.push_back(num);
            mv[i][num] = mp[go];
        }
    }

    dp[0][0][0] = true;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= 1; j++) 
            for (int k = 0; k < cnt; k++) {
                if (dp[i][j][k] == 0) continue;
                if (haiku[k] && j == 0) continue;
                if (len[k] > i) continue;

                for (int num = 1; num <= mxNum; num++) {
                    int goK = mv[k][num];
                    dp[i + 1][j | haiku[goK]][goK] = (dp[i + 1][j | haiku[goK]][goK] + dp[i][j][k]) % mod;
                }
                dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k] * (10 - mxNum)) % mod;
            }

    long long ans = 0;
    for (int i = 0; i < cnt; i++)
        ans = (ans + dp[n][1][i]) % mod;

    cout << ans << endl;

    return 0;
}
