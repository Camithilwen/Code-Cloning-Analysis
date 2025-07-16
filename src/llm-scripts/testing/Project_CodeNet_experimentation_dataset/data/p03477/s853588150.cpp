#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

/*追加部分*/



/*main関数*/

int main() {
FASTIO;
    int a, b, c, d; cin >> a >> b >> c >> d;

    cout << ((a + b) > (c + d) ? "Left" : (a + b) == (c + d) ? "Balanced" :  "Right") << endl;
return 0;
}