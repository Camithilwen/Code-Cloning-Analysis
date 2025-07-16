#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll

#define _GLIBCXX_DEBUG

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n-1); i >= 0; --i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();
const int BIT = 10;

signed main() {
    int D, G;

    cin >> D >> G;

    vector<int> Ps(D);
    vector<int> Cs(D);
    REP(i, D) {
        cin >> Ps.at(i) >> Cs.at(i);
    }

    // どの問題をコンプリートしたかは、10ビットで表現できる。
    // そこから、それ以上コンプリートしないように注意しつつ、高い配点の問題から解いていく

    int ans = INF;

    REP(tmp, (1 << D)) {
        bitset<BIT> bs(tmp);

        int score = 0;
        int solved = 0;
        REP(i, D) {
            if (bs.test(i)) {
                solved += Ps[i];
                score += 100 * (i+1) * Ps[i] + Cs[i];
            }
        }

        // もし既に達成していたら、それでOK
        if (score >= G) {
            if (solved < ans) {
                ans = solved;

                debug(bs);
                debug(score);
                debug(solved);
                hyphen();
            }
            continue;
        }

        // 達成していない場合は、ポイントの高い問題から解いていく
        REPD(i, D) {
            if (bs.test(i)) {
                continue;
            }

            if (Ps[i] == 1) {
                continue;
            }

            int point = 100 * (i+1);
            int solve_but_one_score = score + (point * (Ps[i] - 1));
            if (solve_but_one_score < G) {
                // まだ足りない → 次へ
                score = solve_but_one_score;
                solved += (Ps[i] - 1);

                continue;
            } else {
                // 足りた → 解き過ぎないようにして〆
                // ceilはx.00001の時がこわい
                int solved_this;
                if ((G - score) % point == 0) {
                    solved_this = (G - score) / point;
                } else {
                    solved_this = (G - score) / point + 1;
                }
                score += point * solved_this;
                solved += solved_this;

                if (solved < ans) {
                    ans = solved;

                    debug(bs);
                    debug(score);
                    debug(solved);
                    hyphen();
                }

                break;
            }
        }

        // ここに辿り着いた時には、もう打つ手立てが無いので、
        // 更新処理を行わない

        // debug(bs);
        // debug(score);
        // debug(solved);
        // hyphen();
    }

    cout << ans << endl;
}
