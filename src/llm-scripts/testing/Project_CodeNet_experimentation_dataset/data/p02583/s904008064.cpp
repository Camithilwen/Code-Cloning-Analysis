#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpi vector<pii>
#define vpl vector<pll> 
#define ss second 
#define ff first

using namespace std;

const int p = 1e9 + 7;
const int maxn = 1e5 + 1;

void solve() {
    int n; cin >> n;
    int l[n];
    // vi psides;
    for(int i = 0; i < n; i++) cin >> l[i];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(l[i] != l[j] && l[i] != l[k] && l[j] != l[k]) {
                    vi sides = {l[i], l[j], l[k]};
                    sort(sides.begin(), sides.end());
                    if(sides[0] + sides[1] > sides[2]) ans++;
                }
            }
        }
    }
    cout << ans;
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}