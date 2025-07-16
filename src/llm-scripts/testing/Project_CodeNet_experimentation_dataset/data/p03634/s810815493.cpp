#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

typedef pair<int, ll> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<p> > x(N, vector<p>());
    vector<bool> C(N);
    vector<ll> L(N);

    for(int i = 0; i < N - 1; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        x[a].push_back(make_pair(b, c));
        x[b].push_back(make_pair(a, c));
    }

    stack<p> s;

    int Q, K;
    cin >> Q >> K;
    K--;

    s.push(make_pair(K, 0));

    while(!s.empty()) {
        p y = s.top();
        s.pop();
        int n = y.first;
        ll l = y.second;

        C[n] = true;
        L[n] = l;

        for(int i = 0; i < x[n].size(); i++) {
            if(C[x[n][i].first]) continue;
            s.push(make_pair(x[n][i].first, l + x[n][i].second));
        }
    }

    vector<int> a(Q);
    vector<int> b(Q);

    for(int i = 0; i < Q; i++) cin >> a[i] >> b[i];

    for(int i = 0; i < Q; i++) {
        a[i]--;
        b[i]--;
        cout << L[a[i]] + L[b[i]] << endl;
    }
}