#include <bits/stdc++.h>
using namespace std;

int n,x,y,z;
typedef long long ll;
const int N = 41, MAXM = (1 << 18) + 50, mod = (int)1e9 + 7;

map<vector<int>, int> mp;

int cnt = 0;
int dp[N][MAXM];
int nxt[MAXM][11];
bool haiku[MAXM];

//vector<vector<int> > seqs;

int cumul(vector<int> &V, int cur, int sum) {
    while(cur < V.size() && sum > 0) sum -= V[cur], cur++;
    if(sum != 0) return -1;
    return cur;
}

bool is_haiku(vector<int> &V) {
    int sum = 0;
    for(int x : V) sum += x;
    if(sum != x + y + z) return false;
    int cur = 0;
    if((cur = cumul(V, cur, x)) == -1) return false;
    if((cur = cumul(V, cur, y)) == -1) return false;
    return cumul(V, cur, z) != -1;
}

int get(vector<int> &V) {
    if(!mp.count(V)) {
        haiku[cnt] = is_haiku(V);
//        seqs.push_back(V);
        mp[V] = cnt++;
    }
    return mp[V];
}

void add(int &to, int x) {
    to += x;
    if(to >= mod) to -= mod;
}

string tostr(vector<int> &V) {
    string s;
    for(int x : V) s.push_back((char)(x + '0'));
    return s;
}

int main() {
    cin >> n >> x >> y >> z;
    int mn = max(x, max(y, z));
    vector<int> V;
    int id0 = get(V);
    for(int i = 1; i <= mn; i++) {
        vector<int> nV(1, i);
        nxt[id0][i] = get(nV);
    }
    for(int len = 1; len <= x + y + z; len++) {
        for(int i = 0; i < (1 << (len-1)); i++) {
            vector<int> sV;
            int cur = 1;
            bool bad = false;
            for(int j = 0; j < len - 1; j++) {
                if((i >> j) & 1) {
                    if(cur > mn) {
                        bad = true;
                        break;
                    }
                    sV.push_back(cur), cur = 1;
                }
                else cur++;
            }
            if(cur > mn || bad) continue;
            sV.push_back(cur);

            int c_id = get(sV);
            for(int k = 1; k <= mn; k++) {
                vector<int> nV;
                nV.push_back(k);
                nV.insert(nV.end(), sV.begin(), sV.end());
                int sum = len + k;
                while(!nV.empty() && sum > x + y + z) {
                    sum -= nV.back();
                    nV.pop_back();
                }
                nxt[c_id][k] = get(nV);
            }
        }
    }

//    for(int i = 0; i < cnt; i++) {
//        for(int x : seqs[i]) cout << x << " ";
//        cout << endl;
//    }

//    cout << cnt << endl;
//    for(int i = 0; i < cnt; i++) {
//        cout << "nxts of " << tostr(seqs[i]) << endl;
//        if(haiku[i]) cout << "is haiku" << endl;
//        for(int k = 1; k <= 10; k++) cout << k << ": " << tostr(seqs[nxt[i][k]]) << endl;
//    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < cnt; j++) {
            if(haiku[j]) continue;
            for(int k = 1; k <= 10; k++) add(dp[i][nxt[j][k]], dp[i-1][j]);
        }
    }
    ll res = 1;
    for(int i = 0; i < n; i++) res *= 10, res %= mod;
    int f_res = 0;
    for(int i = 0; i < cnt; i++) if(!haiku[i]) add(f_res, dp[n][i]);
    cout << (res - f_res + mod) % mod << endl;

}