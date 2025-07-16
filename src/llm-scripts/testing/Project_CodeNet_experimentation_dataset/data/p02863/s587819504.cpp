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

int n,t;
vector< pair<int,int> >v;
int cache[3004][3004];

int dp(int pos,int time) {
    if(pos == n || time >= t) {
        return 0;
    }

    int &ans = cache[pos][time];
    if(ans != -1) {
        return ans;
    }

    ans = dp(pos+1, time);
    ans = max(ans, v[pos].second + dp(pos+1, time + v[pos].first));
    return ans;

}

int32_t main() {
    IOS;
    start();

    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    memset(cache, -1, sizeof(cache));
    print(dp(0,0));
}   