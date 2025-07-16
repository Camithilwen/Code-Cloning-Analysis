#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50005;
const int MOD = 1000000007;

int n, x, y, z, cnt;
int p[10][MAXN], fin[10][MAXN], t[MAXN];
int dp[2][45][MAXN];
map <string, int> mp;
string r[MAXN];

vector <string> f (int x) {
    vector <string> res;
    if (x == 0) {
        res.push_back("");
        return res;
    }
    for (int i=0; i<x; i++) {
        vector <string> tmp = f(i);
        for (auto s : tmp) res.push_back(((char) (x - i + '0')) + s);
    }
    return res;
}

void ubaci (string s) {
    int len = s.size();
    int curr = 0;
    for (int i=0; i<len; i++) {
        int d = s[i] - '0';
        if (p[d][curr] == 0) p[d][curr] = ++cnt;
        curr = p[d][curr];
    }
    t[curr] = 1;
}

void dfs (string s, int br) {
    mp[s] = br;
    r[br] = s;
    for (int i=0; i<10; i++) {
        if (p[i][br]) dfs(s + ((char) (i + '0')), p[i][br]);
    }
}

void gen () {
    vector <string> sx = f(x), sy = f(y), sz = f(z);
    for (auto s1 : sx) {
        for (auto s2 : sy) {
            for (auto s3 : sz) {
                ubaci(s1 + s2 + s3);
            }
        }
    }
    mp[""] = 0;
    dfs("", 0);
    for (int i=0; i<=cnt; i++) {
        int len = r[i].size();
        for (int j=len; j>=0; j--) {
            string suf = r[i].substr(j);
            if (mp.find(suf) != mp.end()) {
                int ind = mp[suf];
                for (int k=0; k<10; k++) {
                    if (p[k][ind] != 0) fin[k][i] = p[k][ind];
                }
            }
        }
    }
}

int f (int flg, int pos, int br) {
    //for (int i=0; i<pos; i++) cout << " ";
    //cout << "bla " << flg << " " << pos << " " << br << endl;
    if (dp[flg][pos][br] != -1) return dp[flg][pos][br];
    if (pos == n) return flg;
    int res = 0;
    for (int i=0; i<10; i++) {
        res = (res + f(flg | t[fin[i][br]], pos + 1, fin[i][br])) % MOD;
    }
    return dp[flg][pos][br] = res;
}

int main () {
    memset(dp, -1, sizeof dp);
    cin >> n >> x >> y >> z;
    gen();
    cout << f(0, 0, 0);
    return 0;
}
