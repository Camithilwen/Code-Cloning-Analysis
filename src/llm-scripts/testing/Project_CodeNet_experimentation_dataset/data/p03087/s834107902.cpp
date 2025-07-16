#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, q, l, r;
    string s;
    cin >> n >> q >> s;

    vector<int> ac(n + 1, 0);

    for (int i = 1; i < n; i++) {
        if (s[i-1] == 'A' && s[i] == 'C') ac[i] = ac[i-1] + 1;
        else ac[i] = ac[i-1];
    }


    vector<int> ans(q, 0);
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        ans[i] = ac[r-1] - ac[l-1];
    }

    for (int i = 0; i < q; i++) cout << ans[i] << endl;
    
}