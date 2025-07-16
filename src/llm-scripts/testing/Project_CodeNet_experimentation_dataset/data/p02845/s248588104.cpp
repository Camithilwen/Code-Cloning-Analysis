#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 29);
ll k, m, n,h,w,v;
const ll MOD= 1000000007;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n; ll sum = 1;
    vector<int> a(n + 1), c(3, 0);
    req(i, n) cin >> a[i];
    req(i, n) {
        ll cnt = 0, id = -1;
        if (a[i] == c[0]) { cnt++; id = 0; }
        if (a[i] == c[1]) { cnt++; id = 1; }
        if (a[i] == c[2]) { cnt++; id = 2; }
        if (id == -1) {
            cout << 0 << endl;
            return 0;
        }sum *= cnt; c[id]++;
        sum %= MOD;
    }cout << sum << endl;
}