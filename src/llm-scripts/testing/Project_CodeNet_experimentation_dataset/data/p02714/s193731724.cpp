#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> r,g,b;

    for(int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if(x=='R') r.push_back(i+1);
        if(x=='G') g.push_back(i+1);
        if(x=='B') b.push_back(i+1);
    }

    ll ans = r.size()*g.size()*b.size();
    if(ans==0){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < r.size(); i++) {
        for(int j = 0; j < g.size(); j++) {
            int y=lower_bound(b.begin(),b.end(),g[j]+g[j]-r[i])-b.begin();
            if(y!=b.size()){
                if(b[y]==g[j]+g[j]-r[i]) ans--;
            }
            y=lower_bound(b.begin(),b.end(),r[i]+r[i]-g[j])-b.begin();
            if(y!=b.size()){
                if(b[y]==r[i]+r[i]-g[j]) ans--;
            }

            if((r[i]+g[j])%2==0){
                y=lower_bound(b.begin(),b.end(),(r[i]+g[j])/2)-b.begin();
                if(y!=b.size()){
                if(b[y]==(r[i]+g[j])/2) ans--;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}