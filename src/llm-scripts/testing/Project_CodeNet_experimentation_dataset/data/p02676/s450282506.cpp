#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

int main() {
    int k;
    cin >> k;
    string n;
    cin >> n;

    if (n.size() > k) {
        string ans = "";
        rep (i, n.size()) {
            if (i < k) ans += n[i];
            else {
                ans += "...";
                break;
            }
        }

        cout << ans << endl;
        return 0;
    }

    cout << n << endl;
    return 0;
}