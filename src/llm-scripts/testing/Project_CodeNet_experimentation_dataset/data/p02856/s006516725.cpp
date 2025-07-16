#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

ii mer(int a, int b) {
    int op = 0;
    while (1) {
        ++op;
        if (a + b < 10)
            return mp(a+b,op);
        else
            tie(a,b) = mp((a+b)/10, (a+b)%10);    
    }   
}   

ii mr[10][10];
ii mem[10][60];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            mr[i][j] = mer(i, j);

    for (int c = 0; c < 10; ++c) {
        mem[c][0] = mp(c, 0);
        for (int i = 1; i < 60; ++i) {
            auto t = mr[mem[c][i - 1].f][mem[c][i - 1].f];
            mem[c][i] = mp(t.f, t.s + mem[c][i - 1].s * 2);
        }   
    }   

    int n;
    cin >> n;
    int ans = 0;
    vector <int> ar;
    for (int i = 0; i < n; ++i) {
        int d, k;
        cin >> d >> k;
        int c = d;
        --k;
        for (int j = 0; j < 60; ++j) {
            if ((k >> j) & 1) {
                ii add = mem[d][j];
                auto t = mr[c][add.f];
                ans += t.s;
                ans += add.s;
                c = t.f;
            }   
        }
        ar.app(c);   
    }    
    int cur = ar[0];
    for (int i = 1; i < ar.size(); ++i) {
        ii t = mr[cur][ar[i]];
        cur = t.f;
        ans += t.s;
    }   
    cout << ans << endl;
}