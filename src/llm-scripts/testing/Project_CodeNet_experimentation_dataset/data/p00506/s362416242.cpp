#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n; cin >> n;
    int N[n], n_min = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> N[i];
        if (N[i] < n_min) n_min = N[i];
    }
    for (int j = 1; j <= n_min; j++) {
        bool div_all = true;
        for (int i = 0; i < n; i++) if (N[i] % j != 0) div_all = false;
        if (div_all == true) cout << j << endl;
    }
}
