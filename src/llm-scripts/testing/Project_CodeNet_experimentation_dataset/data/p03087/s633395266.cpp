#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;
typedef long long ll;

int main() {
    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;
    vector<vector<int>> data(Q, vector<int>(2));
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> data.at(i).at(j);
        }
    }
    vector<int> rsum(N + 1, 0);
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S.at(i) == 'A' && S.at(i + 1) == 'C') {
            sum++;
        }
        rsum.at(i + 1) = sum;
    }
    int ans;
    for (int i = 0; i < Q; i++) {
        ans = rsum.at(data.at(i).at(1) - 1) - rsum.at(data.at(i).at(0) - 1);
        cout << ans << endl;
    }
}