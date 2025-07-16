#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>A(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i-1];
        A[i]%=M;
    }
    sort(A.begin(),A.end());
    int ans = 0;
    int cnt = 1;
    for(int i = 1; i <= N; i++) {
        if(A[i] == A[i-1]) {
            cnt++;
        }
        else {
            ans += cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    ans += cnt*(cnt-1)/2;
    cout << ans << endl;
}