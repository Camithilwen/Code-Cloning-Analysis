#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;


ll n;
string s;
ll a[200005];
ll b[200005];
const ll mod = 1e9 + 7;
ll ans;
ll suf[200005];
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> n; n+=n;
        cin >> s;
        if(s[0] == 'W' || s[n-1] == 'W'){
                cout << "0\n"; return 0;
        }
        a[0]=1;
        ll cnt = 1;
        ll tc=1;
        b[0]=1;
        ll L = 1;
        ll R = 0;
        for(ll i=1;i<n;i++) {
                if(s[i] == s[i-1]){
                        b[i] =1-b[i-1];
                }else b[i] = b[i-1];
                if(b[i]) L++;
                else R++;
        }
        if(L != R){
                cout << "0\n"; return 0;
        }
        ans=1LL;
        for(ll i=n-1;i>=0;i--) {
                suf[i] = suf[i+1] + b[i];
        }
        ll l=0;
        ll r=0;
        for(ll i=0;i<n;i++) {
                if(b[i] == 0){
                        ans = (ans * (l-r))%mod;
                        r++;
                }else l++;
        }
        for(ll i=1;i<=(n/2);i++) ans = (ans * i)%mod;
        cout << ans << endl;
        return 0;
}
