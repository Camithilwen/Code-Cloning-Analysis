#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    ll a[n];
    rep(i, n){
        cin >> a[i];
    }

    double a_sum = accumulate(a, a+n, 0LL);
    double ave = a_sum / n;

    double vmin = 1e18;
    ll i_ans = 0;
    rep(i, n){
        double dif = abs(ave - a[i]);
        if(dif < vmin){
            i_ans = i;
            vmin = dif;
        }
    }

    cout << i_ans << endl;

    return 0;
}