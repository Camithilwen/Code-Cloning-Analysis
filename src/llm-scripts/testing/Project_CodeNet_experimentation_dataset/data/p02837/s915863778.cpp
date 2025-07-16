#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int main() {
    int n,a[16],x[16][16],y[16][16];
    cin>> n;
    rep(i,n) {
        cin>>a[i];
        rep(j,a[i]) {
            cin>>x[i][j]>>y[i][j];
        }
    }
    int ans = 0;
    for (int bit = 0;bit<(1<<n);bit++) {
        int count=0;
        bool end = false,last=false;
        for (int i = 0;i<n;i++) {
            if((1<<i) & bit) {
                rep(j,a[i]) {
                    if(y[i][j] != ((bit>>(x[i][j]-1))&1)) {
                        end = true;
                        break;
                    }
                }
                if(end) {
                    last=true;
                    break;
                } else {
                    count++;
                }
            }
        }
        if(!last) ans = max(ans,count); 
    }

    cout<<ans<<endl;
}