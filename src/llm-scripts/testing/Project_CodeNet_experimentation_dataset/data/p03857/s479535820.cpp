#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5 + 3;

int pai[3][T];
int peso[3][T];
vii g[T];
int n,k,l;

void init() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <= n; j++) {
            pai[i][j] = j;
            peso[i][j] = 1;
        }
}

int find(int op, int x) {
    return (pai[op][x] == x? x : pai[op][x] = find(op,pai[op][x]));
}

void join(int op, int x, int y) {
    x = find(op,x);
    y = find(op,y);
    if(x == y) return;
    if(peso[op][x] < peso[op][y]) swap(x,y);
    pai[op][y] = x;
    peso[op][x] += peso[op][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> l;
    init();

    while(k--) {
        int a,b; cin >> a >> b;
        if(find(0,a) != find(0,b)) join(0,a,b);
    }

    while(l--) {
        int a,b; cin >> a >> b;
        if(find(1,a) != find(1,b)) join(1,a,b);
    }

    for(int i = 1; i <= n; i++)
        g[find(0,i)].eb(find(1,i),i);

    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        for(int j = 1; j < g[i].size(); j++)
            if(g[i][j].fi == g[i][j-1].fi)
                join(2,g[i][j].se,g[i][j-1].se);
    }

    for(int i = 1; i <= n; i++) cout << peso[2][find(2,i)] << " ";
    cout << endl;

    return 0;
}
