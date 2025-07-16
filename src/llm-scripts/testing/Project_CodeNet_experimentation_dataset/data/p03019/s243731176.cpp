#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

using namespace std;

struct Sub {
    lint b, l, r;
    Sub(int b = 0, int l = 0, int r = 0) : b(b), l(l), r(r) {}
};

int main() {
    lint N, X;
    cin >> N >> X;

    vector<Sub> subs(N);
    for (auto& s : subs) {
        cin >> s.b >> s.l >> s.r;
    }
    sort(subs.begin(), subs.end(), [&](Sub a, Sub b) {
        return a.r * (X - a.b) + a.l * a.b > b.r * (X - b.b) + b.l * b.b;
    });

    // 勉強時間で二分探索
    lint ok = N * X, ng = -1;
    while (ok - ng > 1) {
        lint mid = (ok + ng) / 2;

        lint score = 0;  // 先頭からmid/X科目だけX点を取り、他は0点
        for (int i = 0; i < N; ++i) {
            if (i < mid / X) {
                score += subs[i].r * (X - subs[i].b);
            } else {
                score -= subs[i].l * subs[i].b;
            }
        }

        lint R = mid % X;
        bool judge = (score >= 0);

        int n = mid / X;
        if (R > 0) {
            for (int r = 0; r < N; ++r) {
                lint nscore = score;
                if (r < n) {
                    // r番目を消してn番目を追加
                    nscore -= subs[r].r * (X - subs[r].b) + subs[r].l * subs[r].b;
                    nscore += subs[r].l * min(subs[r].b, R) + subs[r].r * max(0LL, R - subs[r].b);
                    nscore += subs[n].r * (X - subs[n].b) + subs[n].l * subs[n].b;
                } else {
                    // r番目を追加する
                    nscore += subs[r].l * min(subs[r].b, R) + subs[r].r * max(0LL, R - subs[r].b);
                }
                if (nscore >= 0) judge = true;
            }
        }

        (judge ? ok : ng) = mid;
    }

    cout << ok << endl;
    return 0;
}
