#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main () {
    int n;
    cin >> n;
    int a[n];
    vector<pair<int, int> > vec[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++) {
            int x, y;
            cin >> x >> y;
            vec[i].push_back(make_pair(x - 1, y));
        }
    }
    int max = 0;
    for (int i = 0; i < (1 << n); i++) {
        int count = 0;
        int honest[n];
        for (int j = 0; j < n; j++) {
            honest[j] = (i >> j) & 1;
            count += (i >> j) & 1;
        }
        bool ok = true;
        for (int k = 0; k < n; k++) {
            if (honest[k]) {
                for (int l = 0; l < a[k]; l++) {
                    if (honest[vec[k][l].first] != vec[k][l].second) {
                        ok = false;
                    }
                }
            }
        }
        if (ok) {
            if (max < count) max = count;
        }
    }
    cout << max << endl;
    return 0;
}