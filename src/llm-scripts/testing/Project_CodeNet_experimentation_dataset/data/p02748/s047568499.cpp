#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
//#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(fm, ...) do{std::printf("%s:%d(%s)", __FILE__, __LINE__, __func__);std::cout << "DEBUG PRINT ";std::printf(fm, __VA_ARGS__);}while(0)
#define DEBUG_VAL(a, b) do{std::printf("%s:%d(%s)", __FILE__, __LINE__, __func__);std::cout <<"DEBUG VAL " << a << ":" << b << endl;}while(0)
#else
#define DEBUG_PRINT(...)do{}while(0);
#define DEBUG_VAL(a, b)do{}while(0);
#endif

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    v1 a(A+1);
    v1 b(B+1);
    int ma = 1e6;
    int mb = 1e6;
    rep(i, A){
        int aa;
        cin >> aa;
        a[i+1] = aa;
        ma = min(ma, aa);
    }
    rep(i, B){
        int bb;
        cin >> bb;
        b[i+1] = bb;
        mb = min(mb, bb);
    }
    int ans = ma+mb;
    rep(i, M){
        int x, y, c;
        cin >> x >> y >> c;
        int value = a[x] + b[y] -c;
        ans = min(ans, value);
    }
    cout << ans << endl;
}
