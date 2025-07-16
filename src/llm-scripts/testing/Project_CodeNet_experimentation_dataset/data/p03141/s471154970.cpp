#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

int bigger(int a, int b) {
    return a >= b ? a : b;
}

int smaller(int a, int b) {
    return a >= b ? b : a;
}


signed main() {
    int N;

    cin >> N;

    vector<int> As(N);
    vector<int> Bs(N);
    REP(i, N) {
        cin >> As.at(i) >> Bs.at(i);
    }

    // (priority, score, ind)
    vector<tuple<int, int, int>> sorted_for_a(N);
    vector<tuple<int, int, int>> sorted_for_b(N);
    REP(i, N) {
        int a = As.at(i);
        int b = Bs.at(i);
        int priority = a + b;
        tuple<int, int, int> ta = make_tuple(priority, a, i);
        tuple<int, int, int> tb = make_tuple(priority, b, i);

        sorted_for_a.pb(ta);
        sorted_for_b.pb(tb);
    }

    sort(REVALL(sorted_for_a));
    sort(REVALL(sorted_for_b));

    queue<tuple<int, int, int>> a_queue;
    for (auto a : sorted_for_a) {
        a_queue.push(a);
    }

    queue<tuple<int, int, int>> b_queue;
    for (auto b : sorted_for_b) {
        b_queue.push(b);
    }

    // それが食べられたことを表す配列
    vector<bool> eaten(N, false);

    // ここから作業開始
    int score_a = 0;
    int score_b = 0;

    tuple<int,int,int> ta;
    tuple<int,int,int> tb;

    while(!a_queue.empty() || !b_queue.empty()) {
        // Aのターン

        // 食べられていない料理が見つかるまで捨てる
        while(true) {
            if (a_queue.empty()) {
                break;
            }

            ta = a_queue.front();
            a_queue.pop();

            int& ind = get<2>(ta);
            if (!eaten.at(ind)) {
                break;
            }
        }

        if (a_queue.empty()) {
            break;
        }

        // Aが食べる処理
        int& a = get<1>(ta);
        int& ind_a = get<2>(ta);
        debug(a);
        debug(ind_a);

        score_a += a;
        debug(ind_a);
        eaten.at(ind_a) = true;

        // 食べられていない料理が見つかるまで捨てる
        while(true) {
            if (b_queue.empty()) {
                break;
            }

            tb = b_queue.front();
            b_queue.pop();

            int& ind = get<2>(tb);
            if (!eaten.at(ind)) {
                break;
            }
        }

        // Bが食べる処理
        // 後攻はもう食べるものが無い可能性がある
        if (b_queue.empty()) {
            break;
        }

        int& b = get<1>(tb);
        int& ind_b = get<2>(tb);
        debug(b);
        debug(ind_b);

        score_b += b;
        debug(ind_b);
        eaten.at(ind_b) = true;
    }

    cout << score_a - score_b << endl;
}
