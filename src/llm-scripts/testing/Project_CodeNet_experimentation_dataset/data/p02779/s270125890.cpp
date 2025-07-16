#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define all(x) x.begin(), x.end()
#define watch(x) cout<<#x<<" : "<<x<<endl
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define testCases int tt;cin>>tt; while(tt--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<string> vs;

int main() {
    fastio;
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    if (s.size() == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}