#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define pi pair <int, int>
#define sz(x) (int)((x).size())
#define int long long

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const ll inf = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 20;
const int NMAX = 1e4 + 11;
const ll INF64 = 3e18 + 1;
const double lil = 0.0000000000001;

//ifstream cin ("test.in");
//ofstream cout ("test.out");

int n, a[N][N], dp[(1 << N)];

int32_t main(){
ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    //create groups
    for(int mask = 0; mask < (1 << n); mask++){

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i)))continue;
            for(int j = 0; j < i; j++){
                if(!(mask & (1 << j)))continue;
                ans += a[i][j];
            }
        }

        dp[mask] = ans;
    }

    for(int mask = 1; mask < (1 << n); mask++){
        for(int i = mask; i; i = (mask & (i - 1))){
            if(dp[mask] < dp[mask - i] + dp[i])dp[mask] = dp[mask - i] + dp[i];
        }
    }

    rc(dp[(1 << n) - 1]);
}
