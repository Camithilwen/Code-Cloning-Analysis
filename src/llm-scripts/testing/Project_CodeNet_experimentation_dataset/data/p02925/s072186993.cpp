#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;



int main() {
    int n; cin >> n;
    vector<vector<int>> graph(n);
    rp(i, 0, n) {
        rp(j, 0, n-1) {
            int a; scanf("%d", &a); a--;
            graph.at(i).emplace_back(a);
        }
    }

    vector<int> prog(n);
    set<int> s;
    rp(i, 0, n) s.insert(i);
    int day = 0;
    while(!s.empty()) {
        set<int> next_s;
        for(auto x: s){
            int y = graph.at(x).at(prog.at(x));
            if(x == graph.at(y).at(prog.at(y))) {
                if(prog.at(x) < n-2) next_s.insert(x);
                if(prog.at(y) < n-2) next_s.insert(y);
            }
        }

        for(auto x: next_s) {
            // printf("%d ", x);
            prog.at(x) ++;
        }
        // printf("\n");
        day++;
        s = next_s;
    }
    rp(i, 0, n) {
        if(prog.at(i) < n-2) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}