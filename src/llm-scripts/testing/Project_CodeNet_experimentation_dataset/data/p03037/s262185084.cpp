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
    int n, m ;
    cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i, m) cin >> l[i] >> r[i];

    int lmax = *max_element(all(l));
    int rmin = *min_element(all(r));
    put(max(0, rmin - lmax + 1));

    

    return 0;
}