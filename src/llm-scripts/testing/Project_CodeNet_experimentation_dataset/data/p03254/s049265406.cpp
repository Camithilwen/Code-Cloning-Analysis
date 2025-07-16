#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    int ans = 0;

    for(int i=0; i<N; i++){
        if(x - a[i] < 0) break;
        if(i == N-1 && x - a[i] != 0) break;
        x -= a[i];
        ans++;
    }
    
    cout << ans << endl;

    return 0;
}