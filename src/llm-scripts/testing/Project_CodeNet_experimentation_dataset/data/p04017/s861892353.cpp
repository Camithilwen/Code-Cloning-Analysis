#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #include"Template.cpp"

int n, l, q;
vector<int> arr;

vector<vector<int>> table;

void preprocess() {
    int curr = 1;
    int i = 1;
    while(i <= n) {
        if(curr == n+1) {
            table[i][0] = curr - 1;
            i ++;
            continue;
        }
        while(curr <= n && (arr[curr] - arr[i]) <= l) {
            curr ++;
        }
        table[i][0] = curr - 1;
        i ++;
    }
    for(int i = n; i > 0; i --) {
        for(int j = 1; j < 30; j ++) {
            int mid = table[i][j-1];
            if(mid != -1) {
                table[i][j] = table[mid][j-1];
            }
        }
    }
}

int query(int l, int r) {
    if(l > r) swap(l, r);
    int ans = 0;
    for(int j = 29; j >= 0; j --) {
        int pw = 1LL << j;
        if(table[l][j] == -1) continue;
        if(arr[table[l][j]] < arr[r]) {
            l = table[l][j];
            ans += pw;
        }
    }
    ++ans;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    arr.assign(n + 1, 0);
    table.assign(n+1, vector<int>(30, -1));
    for(int i = 1; i <= n; i ++) cin >> arr[i];
    cin >> l >> q;
    preprocess();
    // t(table);
    while(q --) {
        int low, high; cin >> low >> high;
        int ans = query(low, high);
        cout << ans << endl;
    }
    return 0;
}