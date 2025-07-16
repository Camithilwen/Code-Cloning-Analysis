#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    int K = 0;
    vector<int> in(5, 0);
    for (int i = 0; i < 5; i++) cin >> in[i];
    cin >> K;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (max(in[i], in[j]) - min(in[i], in[j]) > K && i != j) {
                printf("%s\n", ":(");
                return 0;
            }
        }
    }
    printf("%s\n", "Yay!");
    return 0;
}