#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;



int main(){
    int n,k;
    cin >> n >> k;
    set<int> s;
    rep(i,10) s.insert(i);
    rep(i,k){
        int m;cin >> m;
        s.erase(s.find(m));
    }
    vector<int> temp(5);
    int ans = 100000;
    for(auto m:s)for(auto i:s)for(auto j:s)for(auto k:s)for(auto l:s){
        temp[4] = 10000*m+1000*i+100*j+10*k+l;
        temp[3] = temp[4]%10000;
        temp[2] = temp[4]%1000;
        temp[1] = temp[4]%100;
        temp[0] = temp[4]%10;
        rep(j,5){
            if(temp[j]>=n) ans = min(ans,temp[j]);
        }
    }
    cout << ans << endl;


}