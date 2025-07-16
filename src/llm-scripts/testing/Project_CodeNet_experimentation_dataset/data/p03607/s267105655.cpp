#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    unordered_map<ll, int> c;
    rep(i, n) c[A[i]] = 0;
    rep(i, n) c[A[i]]++;

    int sum = 0;
    for (auto kv: c) {
        if (kv.second % 2 == 1)
            sum++;
    }    

    put(sum);
    
    return 0;
}