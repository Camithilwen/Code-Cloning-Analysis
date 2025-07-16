#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 5e5 + 2;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, x;
    cin >> n >> x;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; i + j <= min(n, x); j++) {
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            for (int k = 0; k < i; k++)
                pq.push(a[k]);
            for (int k = n - 1, c = 0; c < j; c++, k--)
                pq.push(a[k]);
            for (int k = i + j; k < x; k++) {
                if (!pq.empty() && pq.top() < 0) pq.pop();
            }
            ll val = 0;
            while(!pq.empty()) val += pq.top(), pq.pop();
            sum = max(sum, val);
        }
    }
    cout << sum;
    return 0;
}