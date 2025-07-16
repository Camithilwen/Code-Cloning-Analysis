#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, M, tmp=0;
vector<pair<ll,ll>> ans;

signed main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++) {
        tmp = 0;
        if(N%2==0&&4*i>=N) tmp++;
        cout << (N-i-tmp)%N << " " << (N+i)%N << endl;
    }
    return 0;
}