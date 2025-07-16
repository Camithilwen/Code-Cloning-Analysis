#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <numeric>
#include <iomanip>
#define ll long long
#define pi 3.14159265358979323846
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
/*　BFS
 vector<vector<ll>> g(n+1);
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dist(n+1, -1);
    queue<ll> que;
    que.push(1);
    dist[1] = 0;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll nv : g[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
*/

int main(){
    ll n, m;
    cin >> n >> m;
    ll a[n];
    map<ll, ll> I{};
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= m;
        I[a[i]]++;
    }
    ll sum[n+1];
    sum[0] = a[0]%m;
    for(ll i = 1; i < n; i++){
        sum[i] = sum[i-1]+a[i];
        sum[i]%=m;
    }
    sort(sum, sum+n);
    sum[n] = -11111111111;
    ll ans = 0;
    ll count = 1;
    for(ll i = 0; i < n; i++){
       // cout << sum[i] << endl;
        if(sum[i]==0) ans++;
        if(sum[i]==sum[i+1]) count++;
        else {
            ans += count*(count-1)/2;
            count = 1;
        }
    }
    ans += count*(count-1)/2;
    cout << ans << endl;
    return 0;
}
