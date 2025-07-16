#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void printArray(ll A[], int size) {
    for (int i = 0; i <= size - 1; i++) cout << A[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v;
    int tot = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (i + 1 <= n - 1 && s[i] == 'A' && s[i + 1] == 'C') tot++;
        v.push_back(tot);
    }
    for (int i = n - 1; i >= 1; i--) {
        //cout << 'h' << '\n';
        v[i] = v[i - 1];
    }
    v[0] = 0;
    //printVector(v);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << v[r] - v[l] << '\n';
    }
    return 0;
}