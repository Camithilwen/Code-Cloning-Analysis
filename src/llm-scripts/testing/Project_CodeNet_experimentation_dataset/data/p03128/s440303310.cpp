#include <bits/stdc++.h>
using namespace std;

const int x[10] = {-1,2,5,5,4,5,6,3,7,6};
void chmax(int &a, const int &b) { if (a < b) a = b; return; }

int main(){
    int n, m; cin >> n >> m;

    vector<int> data(m);
    for (int i = 0; i < m; i++) cin >> data[i];
    sort(data.begin(),data.end(),greater<int>());

    vector<int> keta(n+1,-1); keta[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - x[data[j]] >= 0) chmax(keta[i], keta[i - x[data[j]]] + 1);
        }
    }

    while (n > 0) {
        for (int i = 0; i < m; i++) {
            if (n - x[data[i]] >= 0 && keta[n] == keta[n - x[data[i]]] + 1) {
                cout << data[i];
                n -= x[data[i]];
                break;
            }
        }
    }
    return 0;
}