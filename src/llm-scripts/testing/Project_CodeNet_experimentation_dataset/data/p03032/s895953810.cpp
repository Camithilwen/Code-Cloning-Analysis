#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int ans = 0;
    rep(i,n+1) for(int j = 0; j+i <= n; j++){
        if(i+j > k) continue;
        priority_queue<int,vector<int>,greater<int>> pq;
        if(i+j == 0) continue;
        rep(l,i) pq.push(v[l]);
        rep(l,j) pq.push(v[n-1-l]);
        rep(l,k-i-j) if(!pq.empty() && pq.top() < 0) pq.pop();
        int tmp = 0;
        while(!pq.empty()){
            tmp += pq.top();
            pq.pop();
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}