#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int a, b, m;
    cin >> a >> b >> m;

    vector<int> price_a(a);
    vector<int> price_b(b);

    int min_a = INT_MAX;
    for (int& x: price_a) {
        cin >> x;
        min_a = min(min_a, x);
    } 
    int min_b = INT_MAX;
    for (int& x: price_b) {
        cin >> x;
        min_b = min(min_b, x);
    }

    int ans = min_a + min_b;

    int x, y ,z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        ans = min((price_a[x-1] + price_b[y-1] - z), ans);
    }

    cout << ans << endl;

    
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
