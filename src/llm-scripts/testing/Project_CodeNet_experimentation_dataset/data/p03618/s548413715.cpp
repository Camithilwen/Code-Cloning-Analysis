#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<vector<ll>> A;
string S;

signed main(){
    cin >> S;
    A.resize(26);
    for(int i=0;i<S.size();i++) {
        ll abc = S[i]-'a';
        //cout << abc << endl;
        A[abc].push_back(i);
    }
    for(int i=0;i<26;i++) {
        for(int j=0;j<A[i].size();j++) {
            tmp = S.size()-A[i][j]-A[i].size()+j;
            ans += max(tmp, 0LL);
            //cout << ans << endl;
        }
    }
    cout << ans+1 << endl;
    return 0;
}