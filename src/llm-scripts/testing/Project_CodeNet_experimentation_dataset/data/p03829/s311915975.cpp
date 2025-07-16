#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    int X[N];
    for(int i=0; i<N; i++) cin >> X[i];

    sort(X, X+N);

    int now = X[0];
    ll ans = 0;
    for(int i=0; i<N; i++){
        ll w = (ll)A*(X[i] - now);
        ll t = B;
        ans = ans + min(w, t);
        now = X[i];
    }

    cout << ans << endl;

    return 0;
}
