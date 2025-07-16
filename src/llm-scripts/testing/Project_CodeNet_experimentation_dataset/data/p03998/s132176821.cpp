#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;

    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    size_t a = 0, b = 0, c = 0;
    char turn = sa[a++];

    while (true) {

        if (turn == 'a') {
            if (sa.size() == a) {
                cout << "A\n";
                return 0;
            }
            turn = sa[a++];
        } else if (turn == 'b') {
            if (sb.size() == b) {
                cout << "B\n";
                return 0;
            }
            turn = sb[b++];
        } else if (turn == 'c') {
            if (sc.size() == c) {
                cout << "C\n";
                return 0;
            }
            turn = sc[c++];
        }
    }
}
