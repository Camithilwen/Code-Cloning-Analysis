#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        if(i==0&&a!=0) {
            cout << -1 << endl;
            return 0;
        }
        if(tmp+1<a) {
            cout << -1 << endl;
            return 0;
        }
        else {
            if(tmp+1>a) {
                ans += a;
            }
            else {
                ans += a-tmp;
            }
        }
        tmp = a;
    }
    cout << ans << endl;
    return 0;
}