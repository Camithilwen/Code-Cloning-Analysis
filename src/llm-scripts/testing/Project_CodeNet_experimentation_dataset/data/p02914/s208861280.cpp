#include <bits/stdc++.h>
#define fi first
#define se second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
 
int n;
ll a[N], p[62];
 
void insert(ll x) {
    for(int i = 60; i >= 0; i--) {
        if(x >> i & 1) {
            if(!p[i]) {
                p[i] = x;
                break;
            }
            x ^= p[i];
            //cout<<x<<endl;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ll all = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], all ^= a[i];
    for(int i = 0; i <= 60; i++) {
        if(all >> i & 1) {
            for(int j = 1; j <= n; j++) {
                if(a[j] >> i & 1) a[j] -= (1ll << i);
            }
        }
    }
    for(int i = 1; i <= n; i++) insert(a[i]);//,cout<<a[i]<<endl;;
    ll ans = 0;
    for(int i = 60; i >= 0; i--) {
    	//cout<<i<<" "<<p[i]<<" "<<(ans&(1ll<<i)==0)<<endl;
    	
    	if((p[i]!=0)&&((ans&(1ll<<i))==0))
    	{
    		ans=p[i]^ans;
    		//cout<<ans<<endl;
		}
    	
    }
    //cout<<ans<<endl;
    cout << ans + (ans ^ all);
    return 0;
}