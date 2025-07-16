#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N)), day(N, vector<int>(N));
    vector<int> index(N);

    rep(i, N) {
        rep(j, N - 1) {
            cin >> A[i][j];
        }
    }

    int maxloop = (N * (N - 1)) / 2;
    int before = 0;
    for (int l = 0; l < maxloop; l++) {
        for (int i = 0; i < N; i++) {
            if (index[i] < N - 1) {
                int to = A[i][index[i]]; 
                if (i + 1 == A[to - 1][index[to - 1]]) {
                    int value = max(day[i][index[i]], day[to - 1][index[to - 1]]);
                    // cout << i + 1 << " " << to << " " << value + 1 << endl;
                    day[i][index[i] + 1] = value + 1;
                    day[to - 1][index[to - 1] + 1] = value + 1;
                    index[i]++; index[to - 1]++;
                }
            }   
        }
        int res = 0;
        for (int i = 0; i < N; i++) {
            res += index[i];
        }
        if (res == before || res == (N - 1) * N) break;
        before = res;
    }

    int sum = 0;
    rep(i, N) sum += index[i];

    int cnt = 0;
    rep(i, N) {
        chmax(cnt, day[i][N - 1]);
    }

    if (sum == (N - 1) * N) {
        cout << cnt << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}