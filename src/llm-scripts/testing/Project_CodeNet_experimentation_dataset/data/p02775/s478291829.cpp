#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    string s;
    cin >> s;
    int size = s.size();
    reverse(s.begin(), s.end());
    s += '0';
    int carry = 0;
    int ans = 0;
    for (int i = 0; i < size + 1; i++) {
        int add = 0;
        if (s.at(i) - '0' + carry <= 4) {
            add = (s.at(i) - '0') + carry;
            carry = 0;
        } else if (s.at(i) - '0' + carry == 5) {
            add = 5;
            if (s.at(i + 1) - '0' >= 5) {
                carry = 1;
            } else {
                carry = 0;
            }
        } else {
            add = 10 - ((s.at(i) - '0') + carry);
            carry = 1;
        }

        ans += add;
    }

    cout << ans << endl;
}