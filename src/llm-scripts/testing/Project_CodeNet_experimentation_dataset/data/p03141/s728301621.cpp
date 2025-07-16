#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 99999999
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    long long ans = 0;
    cin >> n;
    vector <vector<int>> v(n, vector<int>(3));
    int a, b, c;
    for (vector<int>& tmp : v) {
        cin >> a >> b;
        c = a+b;
        tmp[0] = c; tmp[1] = a; tmp[2] = b;
        ans -= b;
    }
  /*
    for(vector<int> tmp : v) {
        cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
    }
    */
    sort(v.begin(), v.end(), greater<>());
    for(int i = 0; i < n; i += 2) {
        ans += v[i][0];
    }
    cout << ans << endl;
    return 0;
}
