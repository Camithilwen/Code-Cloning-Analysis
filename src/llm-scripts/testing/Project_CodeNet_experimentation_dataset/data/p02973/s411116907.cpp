#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> data(n); rep(i,n) cin >> data[i];

    vector<int> ans(1,-data[0]);

    for(int i = 1; i < n; i++){
        int k = upper_bound(all(ans),-data[i]) - ans.begin();
        if(k == ans.size()) ans.push_back(-data[i]);
        else ans[k] = -data[i];
    }
    cout << ans.size() << endl;
}