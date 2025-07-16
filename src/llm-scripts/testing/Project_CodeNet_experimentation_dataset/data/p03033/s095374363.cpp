#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using Grid = vector<vector<int>>;
using vi = vector<int>;

int main() {
    int N, Q;
    cin >> N >> Q;
    list<tuple<int, int, int>> eve;
    rep(i, N) {
        int s, t, x;
        cin >> s >> t >> x;
        eve.emplace_back(s - x, 1, x);
        eve.emplace_back(t - x, -1, x);
    }
    eve.sort();
    set<int> ms;
    rep(i, Q) {
        int p;
        cin >> p;
        while (eve.size() > 0 && get<0>(eve.front()) <= p) {
            if (get<1>(eve.front()) == 1)
                ms.insert(get<2>(eve.front()));
            else
                ms.erase(get<2>(eve.front()));
            eve.pop_front();
        }
        cout << (ms.size() == 0 ? -1 : *(ms.begin())) << endl;
    }
}
