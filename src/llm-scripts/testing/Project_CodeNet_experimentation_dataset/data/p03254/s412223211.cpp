#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// ordered_set X;
// *X.find_by_order(i) = ith largest element (counting from zero)
// X.order_of_key(k) = number of items in X < k (strict lt)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll x;
    
    cin >> N >> x;

    vll A(N);
    for (int i=0;i<N;i++) cin >> A[i];

    sort(all(A));

    int ans = 0;
    for (int i=0;i<N;i++) {
        if (x >= A[i]) {
            x-= A[i];
            ans++;
        }
    }
    if (x > 0 && ans == N) ans = N-1;
    cout << ans << endl;

    return 0;
}
