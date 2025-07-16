# include <bits/stdc++.h>
# define ll long long
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;

int main()
{
    int N; cin >> N;
    vector<ll> A(N); rep (i, N) cin >> A[i];
    vector<ll> B(N); rep (i, N) cin >> B[i];
    vector<ll> C(N); rep (i, N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<ll> sums(N+1);
    sums[0] = 0;
    rep (i, N)
    {
        ll b = B[i];
        auto c = upper_bound(C.begin(), C.end(), b);
        sums[i+1] = sums[i] + distance(c, C.end());
    }

    ll cnt = 0;
    rep (i, N)
    {
        ll a = A[i];
        auto b = upper_bound(B.begin(), B.end(), a);
        ll index = distance(B.begin(), b);
        cnt += sums[N] - sums[index];
    }

    cout << cnt << endl;

    return 0;
}
