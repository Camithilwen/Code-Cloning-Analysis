#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, l;
    cin >> n >> l;
    
    int sum = 0;
    int best = 1e8;
    rep (i, n) {
        int x = l + i;
        sum += x;
        if (abs(best) > abs(x)) {
            best = x;
        }
    }

    sum -= best;
    println(sum)

    return 0;
}