#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool a[26];
    rep(i, 26) a[i] = false;

    rep(i, n) {
        a[s[i] - 'a'] = true;
    }

    rep(i, 26) {
        if(!a[i]) {
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}