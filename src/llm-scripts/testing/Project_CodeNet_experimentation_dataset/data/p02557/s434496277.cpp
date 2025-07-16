#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;

int getrandmax() {
    static uint32_t y = time(NULL);
    y ^= (y << 13); y ^= (y >> 17);
    y ^= (y << 5);
    return abs((int)y);
}
int getrand(int l, int r) { // [l, r]
    return getrandmax() % (r - l + 1) + l;
}


int main(int argc, char *argv[])
{
    
    
    cin.tie(0) ;
    ios::sync_with_stdio(false) ;
    
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end(), greater<int>());
    
    int i = 0;
    bool found = false;
    while (i < n && clock() < 1.95 * CLOCKS_PER_SEC) {
        if (A[i] == B[i]) {
            int j = getrand(i, n - 1);
            if (B[j] == B[i]) {
                j = getrand(0, i);
                if(B[j] != A[i] && B[i] != A[j]){
                    swap(B[i], B[j]);
                }
            } else {
                swap(B[i], B[j]);
            }
            i--;
        }
        i++;
        found = (i == n);
    }
    
    if (found) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cout << B[i];
            } else {
                cout << " " << B[i];
            }
            if(i == n - 1){
                cout << endl;
            }
        }
    } else {
        cout << "No" << endl;
    }
    
    
    return 0;
    
}
