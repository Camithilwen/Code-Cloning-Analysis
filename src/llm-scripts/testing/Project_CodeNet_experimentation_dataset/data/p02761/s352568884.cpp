//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef long long              ll;
typedef long double            ld;
typedef pair<int, int>         pi;
typedef vector<int>            vi;
typedef vector<pair<int, int>> vpi;

#define pb       push_back
#define all(x)   begin(x), end(x)
#define sz(x)    (int)(x).size()
#define ff       first
#define ss       second
#define mp       make_pair
#define lb       lower_bound
#define ub       upper_bound
#define tcase()  int t; cin >> t; while(t--)

const int MOD = 1e9 + 7; // 998244353;
const int MX  = 2e5 + 5;
const ll  INF = 1e18;
const ld  PI  = acos((ld) -1);

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){

    setIO();

    int n, m;
    cin >> n >> m;

    bool ok = true;



    int mpp[n + 1] = {0};

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        if(x > n){
            ok = false;
        }

        if(mpp[x] != 0 && mpp[x] != y){
            ok = false;
        }

        if(x == 1 && y == 0) ok = false;

        else mpp[x] = y;
    }

    if(n == 1 && mpp[1] == 0){
        cout << 0;
        return 0;
    }

    if(m == 0 && n == 1){
        cout << 0;
        return 0;
    }

    if(m == 0 && n > 1){
        if(n == 2) cout << "10";
        else cout << "100";
        return 0;
    }

    if(!ok){
        cout << -1;
        return 0;
    }

    if(mpp[1] == 0){
        mpp[1] = 1;
    }

    for(int i = 1; i <= n; i++) cout << mpp[i];
}
