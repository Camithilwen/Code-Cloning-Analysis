#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
typedef pair<int, int> ii;

const int N = 5e3 + 5;
int n, sum;
vector< pair<int, ii> > vec;
priority_queue<int> pq;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int h, p; cin >> h >> p;
        vec.pb( { h + p, { h, p } } );
    }
    sort(vec.begin(), vec.end() );
    for (auto i : vec) {
        if(sum <= i.se.fi) {
            pq.push(i.se.se);
            sum += i.se.se;
        }
        else {
            if(i.se.se < pq.top() ) {
                sum -= pq.top(); pq.pop();
                sum += i.se.se; pq.push(i.se.se);
            }
        }
    }

    cout << pq.size();

    return 0;
}
