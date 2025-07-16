#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,cur;
    cin >> n;
    long long ans = 0;
    cin >> cur;
    long long tot[3] = { 0,0,cur };
    for (int i = 2; i <= n; i++) {
        cin >> cur;
        if (i % 2) {
            tot[1] = max(tot[1], tot[2]);
            tot[0] += cur;
            tot[2] += cur;
        }
        else {
            tot[0] = max(tot[0], tot[1]);
            tot[1] += cur;
        }
    }
    cout << (n % 2 ? max(tot[0], tot[1]) : max(tot[1], tot[2]));
}