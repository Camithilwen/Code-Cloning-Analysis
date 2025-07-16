#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ll N;
    cin >> N;

    ll A;
    cin >> A;
    ll height = A;
    ll ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        cin >> A;
        if (height > A) {
            ans += height - A;
        }
        else {
            height = A;
        }
    }

    cout << ans << endl;

    return 0;
}