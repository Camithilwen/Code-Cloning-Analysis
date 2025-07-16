#include <bits/stdc++.h>
#define ll long long int
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
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(all(l));
    reverse(all(l));
    int sum = 0;
    rep(i, k) sum += l[i];
    put(sum)
    return 0;
}