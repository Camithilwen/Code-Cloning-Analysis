typedef unsigned long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll m;
    std::cin >> m;
    ll dsum = 0;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll d,c;
        std::cin >> d>>c;
        dsum += c;
        sum += d*c;
    }
    
    std::cout << dsum-1+(sum-1)/9 << std::endl;
}
