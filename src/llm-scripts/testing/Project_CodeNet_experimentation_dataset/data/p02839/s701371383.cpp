//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

void start() {
	#ifndef ONLINE_JUDGE 
		freopen("in", "r", stdin); 
		freopen("out", "w", stdout); 
	#endif
}

int n, m;
int arr[82][82][2];
int cache[81][81][81*162];

int dp(int i, int j, int diff) {
    if(i >= n || j >= m)
        return 1e18;

    if(i == n-1 && j == m-1) {
        return min(abs(diff - arr[i][j][0] + arr[i][j][1]), 
                    abs(diff + arr[i][j][0] - arr[i][j][1]));
    }

    int &ans = cache[i][j][diff];
    if(ans !=-1)
        return ans;

    int ans1 = min(dp(i+1, j, abs(diff - arr[i][j][0] + arr[i][j][1])),
                dp(i+1, j, abs(diff + arr[i][j][0] - arr[i][j][1])));
    int ans2 = min(dp(i, j+1, abs(diff - arr[i][j][0] + arr[i][j][1])),
                dp(i, j+1, abs(diff + arr[i][j][0] - arr[i][j][1])));
    ans = min(ans2, ans1);
    return ans;
}
int32_t main() {
    IOS;
    start();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> arr[i][j][0];
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> arr[i][j][1];
        }
    }

    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0, 0) << endl;
}   