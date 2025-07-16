#define _USE_MATH_DEFIMES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007;
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}







template<class T> class SegmentTreeSum{
    int n = 0;
    std::vector<T> dat;
    T fill = 0;
public:
    SegmentTreeSum(){}
    SegmentTreeSum(int m, T fil = 0){
        fill = fil;
        int i = 1;
        while(i < m) i *= 2;
        n = i;
        dat.resize(2*i - 1);
        for(int j(0), j_len(2*i-1); j < j_len; ++j)
            dat[j] = fill;
    }

    void update(int k, T a){
        k += n - 1;
        T moto = dat[k];
        dat[k] = a;
        while(k){
            k = (k - 1) / 2;
            dat[k] += a - moto;
        }
    }

    void updateIncrease(int k, T a){
        update(k, dat[k+n-1] + a);
    }
    void updateIncrease(int k){
        updateIncrease(k, 1);
    }

    void updateDecrease(int k, T a){
        update(k, dat[k+n-1] - a);
    }
    void updateDecrease(int k){
        updateDecrease(k, 1);
    }

    T getSum(int a, int b, int k=0, int l=0, int r=-1){
        //[a, b[であることに注意
        if(r < 0) r = n;
        if(r <= a || b <= l) return fill;
        if(a <= l && r <= b) return dat[k];

        T vl = getSum(a, b, 2*k+1, l, (l+r)/2);
        T vr = getSum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }

    T getvalue(int k){
        return dat[k+n-1];
    }

    bool getExist(int l, int r){//全て非負と仮定
        //[l, r]
        return (getSum(l, r+1) > fill);
    }
};

int main(){
    int N, Q; std::cin >> N >> Q;
    SegmentTreeSum<long long> st(N);
    {
        int a;
        for(int i(0); i < N; ++i){
            std::cin >> a;
            st.update(i, a);
        }
    }
    {
        int op, l, r;
        for(int i(0); i < Q; ++i){
            std::cin >> op >> l >> r;
            if(op) std::cout << st.getSum(l, r) << "\n";
            else st.updateIncrease(l, r);
        }
    }
    return 0;
}
