#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=1, tmp=0;
vector<char> A;
vector<ll> B;

signed main(){
    cin >> N;
    for(int i=0;i<2*N;i++) {
        char a;
        cin >> a;
        A.push_back(a);
    }
    ll ct=0;
    for(int i=0;i<A.size()-1;i++) {
        if(A[i]==A[i+1]) {
            ct++;
            //cout << ct << endl;
        }
        if(ct%2==1) {
            tmp = i+1-2*B.size();
            B.push_back(tmp);
            if(tmp<=0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if(A[0]=='W'||ct%2==0||B.back()!=1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i=0;i<B.size();i++) {
        ans *= B[i];
        ans %= MOD;
        //cout << B[i] << endl;
    }
    //cout << ans << endl;
    for(int i=1;i<=N;i++) {
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}