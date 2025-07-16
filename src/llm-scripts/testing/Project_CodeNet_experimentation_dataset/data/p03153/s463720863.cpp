#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int n;
    ll d;
    cin >> n >> d;
    ll a[200005];
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        que.push(P(a[i], i));
    }
    bool used[200005]{0};
    ll ans = 0;
    while(que.size()){
        P p = que.top();
        que.pop();
        int u = p.second;
        if(u > 0 && !used[u]){
            ans += d + a[u] + a[u - 1];
            if(d + a[u] < a[u - 1]){
                a[u - 1] = d + a[u];
                que.push(P(a[u - 1], u - 1));
            }
            used[u] = true;
        }
        if(u < n - 1 && !used[u + 1]){
            ans += d + a[u] + a[u + 1];
            if(d + a[u] < a[u + 1]){
                a[u + 1] = d + a[u];
                que.push(P(a[u + 1], u + 1));
            }
            used[u + 1] = true;
        }
    }
    cout << ans << endl;
}
