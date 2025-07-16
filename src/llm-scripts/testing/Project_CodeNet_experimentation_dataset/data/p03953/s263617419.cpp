#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const int MAXN = 2e5 + 21, LG = 61;

int n, m;
long long k;
long long a[MAXN], d[MAXN], p[MAXN][LG];
vector <long long> res;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    res.pb(a[1]);
    
    cin >> m >> k;

    for (int i = 1; i < n; i++) {
        d[i] = a[i + 1] - a[i];
        p[i][0] = i;
    }

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        swap(p[x - 1][0], p[x][0]);
    }

    for (int i = 1; i < LG; i++)
        for (int j = 1; j < n; j++) {
            p[j][i] = p[p[j][i - 1]][i - 1];
        }
    
    
    for (int i = 1; i < n; i++) {
        int cur = i;
        
        for (int i = LG - 1; ~i; i--)
            if (k & (1LL << i))
                cur = p[cur][i];
        res.pb(res.back() + d[cur]);
    }

    for (auto y: res)    
        cout << y << '\n';
    return 0;
}

