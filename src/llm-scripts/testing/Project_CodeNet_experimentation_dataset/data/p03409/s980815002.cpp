#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<pii> s(n),l(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        s[i] = make_pair(b,a);
    }
    rep(i,n){
        int c,d;
        cin >> c >> d;
        l[i] = make_pair(c,d);
    }
    sort(l.begin(),l.end());
    int ans = 0;
    rep(i,n){
        sort(s.rbegin(),s.rend());
        rep(j,s.size()){
            if(s[j].second < l[i].first && s[j].first < l[i].second){
                ans++;
                s.erase(s.begin() + j);
                break;
            }
        }
    }
    cout << ans << endl;
}
