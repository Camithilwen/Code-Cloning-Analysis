#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 2;
const int INF = 2e18;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    vector<int> count(N + 1, 0);
    int start = 0;
    {
        set<int> remain;
        for (int i = 1; i <= N; i++) remain.insert(i);
        for (int i = 0; i < N + M - 1; i++) {
            int A, B;
            cin >> A >> B;
            G[A].push_back(B);
            count[B]++;
            remain.erase(B);
        }
        start = *remain.begin();
    }
    vector<int> ans(N + 1, -1), dis(N + 1, -1);
    ans[start] = 0;
    dis[start] = 0;
    queue<int> explore;
    explore.push(start);
    while (!explore.empty()) {
        int now = explore.front();
        explore.pop();
        for (int next : G[now]) {
            count[next]--;
            if (dis[next] < dis[now] + 1) {
                dis[next] = dis[now] + 1;
                ans[next] = now;
            }
            if (count[next] == 0) explore.push(next);
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << endl;
}
