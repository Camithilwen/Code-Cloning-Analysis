#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

template<class T>
vector<int> kmp(const T &sentence, const T &word) {
    int lenS = (int)sentence.size(), lenW = (int)word.size(), idx = -1, head = 0;
    vector<int> table(lenW + 1, -1), res;
    for (int i = 0; i < lenW; ++i) {
        while (idx >= 0 && word[i] != word[idx])idx = table[idx];
        table[i + 1] = ++idx;
    }

    idx = 0;
    while (head + idx < lenS) {
        if (word[idx] == sentence[head + idx]) {
            ++idx;
            if (idx == lenW) {
                res.push_back(head);
                head = head + idx - table[idx];
                idx = table[idx];
            }
        } else {
            head = head + idx - table[idx];
            if (idx > 0)idx = table[idx];
        }
    }
    return res;
}

void solve() {
    int N;
    cin >> N;
    vi A(N), B(N), AA(N), BB(2 * N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> B[i];
    }
    rep(i, N) {
        AA[i] = A[i] ^ A[(i + 1) % N];
        BB[i] = B[i] ^ B[(i + 1) % N];
        BB[i + N] = BB[i];
    }
    BB.pop_back();

    vi found = kmp(BB, AA);
    each(i, found) {
        i = (i == 0 ? i : N - i);
    }
    sort(all(found));

    each(i, found) {
        cout << i << ' ' << (A[i] ^ B[0]) << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}