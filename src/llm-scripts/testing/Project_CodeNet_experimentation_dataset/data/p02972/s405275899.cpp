#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1234567;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[200005];
signed main() {
    int N;
    cin >> N;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int>ans;
    for(int i = N; i >= 1; i--) {
        if(cnt[i]%2 == a[i-1]) {
            continue;
        }
        ans.push_back(i);
        for(int j = 1; j*j <= i; j++) {
            if(i%j == 0) {
                if(j*j == i) {
                    cnt[j]++;
                }
                else {
                    cnt[j]++;
                    cnt[i/j]++;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i) {
            cout << " ";
        }
        cout << ans[i];
    }
}
