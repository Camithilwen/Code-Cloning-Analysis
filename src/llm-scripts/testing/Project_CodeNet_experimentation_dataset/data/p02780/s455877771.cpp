#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define dbg(x) cerr << "[" #x << " : " << x << "]\n";
const int mod = (int)1e9+7;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int p[210000];
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    double ans = 0;
    double s = 0;
    int mx = 0;
    for(int i = 0; i < k; i++) s += (p[i]+1)/2.0;
    ans = s;
    for(int i = k; i < n; i++ ) {
        s -= (p[i-k]+1)/2.0;
        s += (p[i]+1)/2.0;
        ans = max(ans, s);
    }
    printf("%lf\n", ans);
}
