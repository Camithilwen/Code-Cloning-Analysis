#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

constexpr long long mod = 1000000007;
constexpr double eps = 0.00001;

int main() {
    int n;
    cin >> n;
    long long *a = new long long[n];
    multiset<long long> b;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        b.insert(a[i]);
    }
    sort(a,a+n,greater<>());
    int c = 0;
    for(int i = 0;i < n;i++) {
        if(b.find(a[i]) == b.end()) continue;
        b.erase(b.find(a[i]));
        long long t = 1;
        while(t <= a[i]*2) {
            if(b.find(t-a[i]) != b.end()) {
                c++;
                b.erase(b.find(t-a[i]));
                break;
            }
            t = t << 1;
        }
    }
    cout << c << endl;
}
