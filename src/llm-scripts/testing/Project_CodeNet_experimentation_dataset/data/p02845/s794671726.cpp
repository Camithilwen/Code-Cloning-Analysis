#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1000000007;
//const int mod = 998244353;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll cnt[3][n+1];
    cnt[0][0]=0;
    cnt[1][0]=0;
    cnt[2][0]=0;

    for(ll i = 0; i < n; i++) {
        ll c=0;
        while(cnt[c][i]!=a[i]){
            c++;
	        if(c==3){
    	        cout << "0" << "\n";
        	    return 0;
            }
        }
        for(ll j = 0; j < 3; j++) cnt[j][i+1]=cnt[j][i];
        cnt[c][i+1]++;
    }

    for(ll i = 0; i < 3; i++) {
        for(ll j = 0; j < n; j++) {
            cerr << std::right << std::setw(2) << cnt[i][j];
        }
        cerr << "\n";
    }

    ll ans=1;
    for(ll i = 0; i < n; i++) {
        ll tmp=0;
        for(ll j = 0; j < 3; j++) if(a[i]==cnt[j][i]) tmp++;
        cerr << std::right << std::setw(2) << tmp;
        ans=(ans*tmp)%mod;
    }
    cout << ans << "\n";
    return 0;
}