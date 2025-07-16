#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> P;
typedef tuple<int, int, int> T;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
string s;

int num[3][4010]; // 0->R, 1->G, 2->B

ll solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            num[j][i+1] = num[j][i];
        }
        switch(s[i]) {
        case 'R': num[0][i+1]++; break;
        case 'G': num[1][i+1]++; break;
        case 'B': num[2][i+1]++; break;
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j]) continue;
            if ((s[i] == 'R' && s[j] == 'G') || (s[j] == 'R' && s[i] == 'G')) {
                res += num[2][n] - num[2][j];
                if (j + j - i < n && s[j+j-i] == 'B') res--;
            } else if ((s[i] == 'B' && s[j] == 'G') || (s[j] == 'B' && s[i] == 'G')) {
                res += num[0][n] - num[0][j];
                if (j + j - i < n && s[j+j-i] == 'R') res--;
            } else {
                res += num[1][n] - num[1][j];
                if (j + j - i < n && s[j+j-i] == 'G') res--;
            }
        }
    }
    return res;
}

void input() {
    cin >> n >> s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
