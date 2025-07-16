#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9+7;
signed main() {
    int N;
    cin >> N;
    vector<int>cnt(N+1,1);
    for(int i = 2; i <= N; i++) {
        int X = i;
        for(int j = 2; j*j <= i; j++) {
            int Y = j;
            if(X%Y == 0) {
                while(X%Y == 0) {
                    cnt[Y]++;
                    X/=Y;
                }
            }
        }
        if(X != 1) {
            cnt[X]++;
        }
    }
    int ans = 1;
    for(int i = 2; i <= N; i++) {
        ans*=cnt[i];
        ans = ans%INF;
    }
    cout << ans << endl;
}