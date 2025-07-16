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
int main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    vector<ll> B(n);
    rep(i, n) cin >> B[i];
    vector<ll> C(n);
    rep(i, n) cin >> C[i];
        
    sort(all(A));
    sort(all(B));
    sort(all(C));

    vector<int> Ia(n);
    vector<int> Ic(n);

    ll sum = 0;
    rep(i, B.size()) {
        ll b = B[i];
        // b以上Aのインデックスの最後
        Ia[i] = lower_bound(all(A), b) - A.begin();
        // bより大きいBのインデックスの最初
        Ic[i] = upper_bound(all(C), b) - C.begin();

        sum += Ia[i] * (n - Ic[i]);
    }

    put(sum);
    return 0;
}