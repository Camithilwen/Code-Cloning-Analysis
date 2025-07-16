#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int k;
        cin >> k;

        long long cnt_D = 0, cnt_M = 0, cnt_DM = 0, cnt_DMC = 0;
        for (int i = 0; i < n; i++) {
            if (s.at(i) == 'D') cnt_D++;
            else if (s.at(i) == 'M') {
                cnt_M++;
                cnt_DM += cnt_D;
            }
            else if (s.at(i) == 'C') cnt_DMC += cnt_DM;

            if (k - 1 <= i) {
                if (s.at(i - k + 1) == 'D') {
                    cnt_D--;
                    cnt_DM -= cnt_M;
                }
                else if (s.at(i - k + 1) == 'M') cnt_M--;
            }
        }

        cout << cnt_DMC << endl;
    }
}