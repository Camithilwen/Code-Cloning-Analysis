#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
 
long long mod = 1000000007;
 
int main() {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    long long sum = 0;
    long long acc = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum + (a[i] * acc)) % mod;
        /* acc += (a[i] % mod); */
        acc = (acc + a[i]) % mod;
    }
    cout << sum % mod << "\n";
    return 0;
}
