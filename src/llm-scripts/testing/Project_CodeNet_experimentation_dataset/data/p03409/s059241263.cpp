#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<P>ab(N);
    vector<P>cd(N);
    for(int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        ab[i].first = a;
        ab[i].second = b;
    }
    for(int i = 0; i < N; i++) {
        int c,d;
        cin >> c >> d;
        cd[i].first = c;
        cd[i].second = d;
    }
    vector<bool>ok(N,false);
    sort(ab.begin(),ab.end());
    reverse(ab.begin(),ab.end());
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int X = INF;
        int Y = INF;
        for(int j = 0; j < N; j++) {
            if(ab[i].first < cd[j].first && ab[i].second < cd[j].second) {
                if((!ok[j]) && X > cd[j].second) {
                    X = cd[j].second;
                    Y = j;
                }
                
            }
        }
        if(Y != INF) {
            ok[Y] = true;
        }
    }
    for(int i = 0; i < N; i++) {
        if(ok[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}
