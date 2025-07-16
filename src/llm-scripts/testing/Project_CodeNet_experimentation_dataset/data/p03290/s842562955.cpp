#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int d, g;
    cin >> d >> g;
    int p[d], c[d];
    int sum = 0, num_mn = 1001;
    bool ach;
    for (int i = 0; i < d; i++) cin >> p[i] >> c[i];

    for (int bit = 0; bit < (1 << d); bit++) {
        int num_tmp = 0;
        sum = 0;
        ach = false;
        for (int i = 0; i < d; i++) {
            if (bit & (1 << i)) {
                num_tmp += p[i];
                sum += ((i + 1) * 100 * p[i] + c[i]);
            }
        }
        // cout << "1st sum:" << sum << " num_tmp:" << num_tmp << endl;
        if (sum < g) {
            for (int i = d - 1; i >= 0; i--) {
                if (!(bit & (1 << i))) {
                    if (g - sum <= (i + 1) * 100 * (p[i] - 1)) {
                        ach = true;
                        num_tmp += ((g - sum) / ((i + 1) * 100));
                        if ((g - sum) % ((i + 1) * 100) != 0) num_tmp++;
                        break;
                    } else {
                        sum += (i + 1) * 100 * (p[i] - 1);
                        num_tmp += (p[i] - 1);
                    }
                }
            }
        } else
            ach = true;
        if (!ach) num_tmp = 1001;
        num_mn = min(num_mn, num_tmp);
    }

    cout << num_mn << endl;

    return 0;
}