#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue
 
#define FOR(i, a, b) for (ll i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
#define MX 1048600
int n;
ll a[MN];
ll ps[MN];

ll lst[MX]; //last time we saw 0
ll cnt[MX];
pll dp[MX]; //cnt for k, cnt for 0

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        ps[i] = ps[i-1] ^ a[i];
    }
    ll ov = ps[n];
    //cout << ov << "\n";

    if(ov != 0){
        ll isn = 0;
        ll isz = 1;

        FOR(i, 1, n-1){
            if(ps[i] == 0){
                isz = (isn+isz)%MOD;
            } else if(ps[i] == ov){
                isn = (isn+isz)%MOD;
            }
        }

        cout << isz << "\n";
    } else{
        int tm = 0;

        dp[0].f = 1;
        FOR(i, 1, MX-1){
            dp[i].s = 1;
        }

        FOR(i, 1, n-1){
            //cout << ps[i] << " ";
            if(ps[i] == 0){
                tm++;
                dp[0].f = (dp[0].f*2)%MOD;
            } else{
                int j = ps[i];
                int dif = tm-lst[j];
                dp[j].s = (dp[j].s + dp[j].f*dif) % MOD;
                dp[j].f = (dp[j].f + dp[j].s) % MOD;
                lst[j] = tm;
            }
        }
        //cout << "\n";
        ll sm = 0;
        F0R(i, MX){
            /*if(dp[i].f != 0){
                cout << i << " adds " << dp[i].f << "\n";
            }*/
            sm += dp[i].f;
            sm %= MOD;
        }

        //cout << "\n";
        cout << sm << "\n";
    }

    return 0;
}
