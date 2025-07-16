#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> sum(n+1);
    vector<int> l(q),r(q);
    rep(i,q) cin >> l[i] >> r[i];
    sum[0] = 0;
    for(int i=1; i<s.size(); i++){
        if(s[i-1]=='A' && s[i]=='C') sum[i+1]=sum[i]+1; 
        else
        sum[i+1] = sum[i];
    }
    for(int i=0; i<q; i++){
        int ans = sum[r[i]]-sum[l[i]];
        cout << ans << endl;
    }
    return 0;
}