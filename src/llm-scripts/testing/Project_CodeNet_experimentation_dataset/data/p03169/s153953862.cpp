// @author: khangtq1
#include <bits/stdc++.h>

using namespace std;

#define fto(i, a, b) for(int i = a; i < b; ++i)
#define fdto(i, a, b) for(int i = b - 1; i >= a; --i)
#define rep(i, n) for(int i = 0; i < n; ++i)
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << "\n"
#define setpre(x) fixed << setprecision(x)

#define all(arr) (arr).begin(), (arr).end()
#define pb push_back
#define mp make_pair
#define pqueue priority_queue
#define unmap unordered_map //hashmap
#define unset unordered_set //hashset
#define mtset multiset
#define endl '\n'

using ll = long long;
using db = double;
using ii = pair<int, int>;
using vi = vector<int>;

const db PI = acos(-1);

#define MOD 1000000007

void solve();

/// ================================ main ==============================

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int tt =1;
	//cin >> tt;
	while(tt--) {
		solve();
	}
	return 0;	
}

/// ================================ solve =============================

const int MAXN = 305;
double p[MAXN][MAXN][MAXN], ev[MAXN][MAXN][MAXN	];

void solve() {
	int n;
    scanf("%d", &n);
    vector<int> cnt(4);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    p[cnt[1]][cnt[2]][cnt[3]] = 1;
    for(int c = n; c >= 0; --c) {
        for(int b = n; b >= 0; --b) {
            for(int a = n; a >= 0; --a) {
                if(a == 0 && b == 0 && c == 0) {
                    continue;
                }
                if(a + b + c > n) {
                    continue;
                }
                // dp[a][b][c]
                
                double p_waste = (double) (n - (a + b + c)) / n;
                // p_waste + p_waste^2 + ... = S
                // 1 + S = S / p_waste
                double ev_waste = p_waste / (1 - p_waste) + 1;	                
                ev[a][b][c] += ev_waste * p[a][b][c];
                
                // remove 1 -> dp[a-1][b][c]
                // we will eventually choose one of a+b+c
                if(a != 0) {
                    double p_go = (double) a / (a + b + c);
                    p[a-1][b][c] += p[a][b][c] * p_go;
                    ev[a-1][b][c] += ev[a][b][c] * p_go;
                }
                
                // remove 2 -> dp[a+1][b-1][c]
                if(b != 0) {
                    double p_go = (double) b / (a + b + c);
                    p[a+1][b-1][c] += p[a][b][c] * p_go;
                    ev[a+1][b-1][c] += ev[a][b][c] * p_go;
                }
                
                // remove 3
                if(c != 0) {
                    double p_go = (double) c / (a + b + c);
                    p[a][b+1][c-1] += p[a][b][c] * p_go;
                    ev[a][b+1][c-1] += ev[a][b][c] * p_go;
                }
            }
        }
    }
    printf("%.10lf\n", ev[0][0][0]); // + cnt[1] + 2 * cnt[2] + 3 * cnt[3]);
}

/*
==================================+
INPUT:                            |
3
1 1 1
==================================+
OUTPUT:                           |
5.5
==================================+
*/

