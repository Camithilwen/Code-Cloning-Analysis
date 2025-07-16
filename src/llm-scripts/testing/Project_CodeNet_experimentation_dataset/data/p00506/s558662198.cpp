#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    auto gcd = [](int mm, int nn) {
        function<int(int, int)> f = [&f](int m, int n) {
            if (n == 0) {
                return m;
            }
            else {
                return f(n, m % n);
            }
        };
        return f(max(mm, nn), min(mm, nn));
    };
    auto gcd3 = [gcd](int n, int m, int o) { return gcd(n, gcd(m, o)); };
    vector<int> r;
    if (n == 2) {
        int a, b;
        cin >> a >> b;
        const auto s = gcd(a, b);
        for (int i = 1; i <= s; ++i) {
            if (a % i == 0 && b % i == 0) {
                r.push_back(i);
            }
        }
    }
    else {
        int a, b, c;
        cin >> a >> b >> c;
        const auto s = gcd3(a, b, c);
        for (int i = 1; i <= s; ++i) {
            if (a % i == 0 && b % i == 0 && c % i == 0) {
                r.push_back(i);
            }
        }
    }
    for (auto i : r) {
        cout << i << endl;
    }
}
