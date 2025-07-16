#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>B(N);
    vector<int>C(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    sort(A.begin(),A.end());
    sort(C.begin(),C.end());
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        int it = lower_bound(A.begin(),A.end(),B[i])-A.begin();
        cnt*=it;
        it = C.end()-upper_bound(C.begin(),C.end(),B[i]);
        cnt*=it;
        ans+=cnt;
    }
    cout << ans << endl;
}
