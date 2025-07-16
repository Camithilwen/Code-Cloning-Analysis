#include<iostream>
#include<vector>
#include<string>
#include<set>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

using P = pair<int, int>;

const int INF = 1 << 30;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<int> A(H), B(H);
    rep(i, 0, H) {
        cin >> A[i] >> B[i];
        --A[i];
    }
    set<P> path;
    multiset<int> dist;
    rep(i, 0, W) {
        path.emplace(i, i);
        dist.insert(0);
    }
    rep(i, 0, H) {
        vector<P> buf;
        for (auto itr = path.lower_bound(P(A[i], 0)); itr != path.end() && (*itr).first < B[i]; ++itr) {
            buf.push_back(*itr);
        }
        int max_start = -INF;
        P max_path;
        for (auto& p : buf) {
            path.erase(p);
            dist.erase(dist.find(p.first - p.second));
            if (chmax(max_start, p.second)) {
                max_path = p;
            }
        }
        if (max_start > -INF) {
            path.emplace(B[i], max_path.second);
            dist.insert(B[i] == W ? INF : B[i] - max_path.second);
        }
        cout << (*dist.begin() == INF ? -1 : *dist.begin() + i + 1) << endl;
    }
    return 0;
}