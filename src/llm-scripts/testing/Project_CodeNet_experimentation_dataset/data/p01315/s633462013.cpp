#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int n;

    while(cin >> n, n) {
        vector< pair< double, string > > ans;
        for(int i = 0; i < n; i++) {
            string str;
            int p, a, b, c, d, e, f, s, m;
            cin >> str >> p >> a >> b >> c >> d >> e >> f >> s >> m;
            int t = a + b + c + (d + e) * m;
            int cnt = f * m;
            ans.push_back(make_pair(-(cnt * s - p) / (double)t, str));
        }

        sort(ans.begin(), ans.end());
        for(int i = 0; i < n; i++) {
            cout << ans[i].second << endl;
        } cout << "#" << endl;
    }
}

