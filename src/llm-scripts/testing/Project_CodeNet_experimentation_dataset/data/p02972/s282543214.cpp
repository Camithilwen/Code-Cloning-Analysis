#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> b(N, 0);
    for (int i = N; i >= 1; i--) {
        int j = i;
        int count = 0;
        while (j <= N) {
            if (b[j - 1] == 1) count++;
            j += i;
        }
        if (count % 2 != a[i - 1]) b[i - 1] = 1;
    }

    vector<int> output;
    for (int i = 0; i < N; i++) {
        if (b[i] != 0) output.push_back(i + 1);
    }
    cout << output.size() << endl;
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
