#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll MX = 1e18;
    int n,k;
    cin >> n >> k;
    vector<int> neg,pos;
    rep(i,n){
        int temp;cin >> temp;
        if(temp == 0) k--;
        else if(temp < 0) neg.push_back(temp);
        else pos.push_back(temp);
    }
    sort(neg.begin(),neg.end(),greater<int>());
    if(k <= 0){
        cout << 0 << endl;
        return 0;
    }
    int s = pos.size();
    int t = neg.size();
    ll ans = MX;
    ll total = 0;

    if(s >= k){
        total = pos[k-1];
        ans = min(ans,total);
    }
    if(t >= k){
        total = abs(neg[k-1]);
        ans = min(ans,total);
    }

    for(int i = max(0,k-t-1);i<=min(s-1,k-2);i++){
        total = 2*abs(neg[k-i-2]) + pos[i];
        ans = min(ans,total);
    }
    for(int i = max(0,k-s-1);i<=min(t-1,k-2);i++){
        total = 2*pos[k-i-2] + abs(neg[i]);
        ans = min(ans,total);
    }

    cout << ans << endl;
}
