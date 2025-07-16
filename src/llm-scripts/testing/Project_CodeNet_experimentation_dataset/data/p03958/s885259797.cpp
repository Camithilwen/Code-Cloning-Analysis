#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int K, T; cin >> K >> T;
    int a[T]; rep(i, T) cin >> a[i];
    sort(a, a + T, greater<int>());
    int sum = 0;
    rep(i, T - 1)
        sum += a[i + 1];
    cout << ((a[0] - sum - 1 < 0) ? 0 : a[0] - sum - 1) << endl;
}
