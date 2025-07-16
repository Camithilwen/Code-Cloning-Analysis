#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
const  long double eps = 1e-2;
const long double pi = acos(-1.0);
using namespace std;

const int N = 1e5 + 1;
const int LOG = 20;
int n, l;
int x[N];
int up[LOG][N];
void solve(){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> x[i];
        cin >> l;
        
    
        for (int i = 1; i <= n; i++){
            if (i == n){
                up[0][i] = i;
                continue;
            }
            int p = upper_bound(x + 1, x + n + 1, x[i] + l) - x;
            p--;
            up[0][i] = p;
        }
        
    for (int k = 1; k < LOG; k++){
        for (int i = 1; i <= n; i++)
            up[k][i] = up[k - 1][up[k - 1][i]];
    }  
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int ans = 0;
        for (int i = LOG - 1; i >= 0; i--)
            if (up[i][a] < b){
                ans += (1 << i);
                a = up[i][a];
            }
        cout << ans + 1 << endl;
    }
}
int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(3);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int step;
	step = 1;
    for (int i = 1; i <= step; i++){
         solve();
    }
}