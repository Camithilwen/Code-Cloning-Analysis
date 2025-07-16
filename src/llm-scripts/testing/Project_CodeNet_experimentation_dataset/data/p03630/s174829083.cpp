#include <bits/stdc++.h>

#define fr first
#define sc second
#define OK puts("OK");
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;

const int inf = (int)1e9 + 7;
const int N = (int)1e5 + 7;

int n,m;
int top,mx;
int st[N],b[N];

int t[2001][2001];
char a[2001][2001];

int f (int i,int j) {
        return (a[i][j] == '#') ? 1 : 0;
}

int main () {
        cin >> n >> m;

        mx = max(n,m);

        for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= m; j ++)
                        cin >> a[i][j];

        n --;
        m --;

        for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= m; j ++)
                        t[i][j] = f(i,j) ^ f(i + 1,j) ^ f(i,j + 1) ^ f(i + 1,j + 1);

        for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= m; j ++)
                        if(t[i][j]) b[j] = 0;
                        else b[j] ++;

                top = 0;
                for (int j = 1; j <= m; j ++) {
                        while (top && b[st[top]] >= b[j]) {
                                mx = max (mx,(j - st[top - 1]) * (b[st[top]] + 1));
                                top --;
                        }
                        st[++top] = j;
                }
                while (top) {
                        mx = max(mx,(m - st[top - 1] + 1) * (b[st[top]] + 1));
                        top --;
                }
        }
        cout << mx << endl;
}
