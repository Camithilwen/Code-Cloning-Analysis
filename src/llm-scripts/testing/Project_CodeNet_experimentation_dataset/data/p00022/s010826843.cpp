#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    for (int n; cin >> n && n;) {
        vector<int> sequence(n);
        int sum = 0;
        int max_val = numeric_limits<int>::min();
        for (int x, i = 0; i < n && cin >> x; i++) {
            if (sum < 0)
                sum = x;
            else
                sum += x;
            max_val = max(max_val, sum);
        }
        cout << max_val << endl;
    }

    return 0;
}