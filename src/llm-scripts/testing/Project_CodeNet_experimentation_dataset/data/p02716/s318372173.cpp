#define _USE_MATH_DEFINES
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






int main(){
    int N, a; std::cin >> N;
    //dp[i][j] := i-4(0-order)文字まで見て j=(取らない)-(取った)+1
    std::vector<std::vector<long long>> dp(N+4, std::vector<long long>(3, 0));
    for(int i(4), i_len(N+4); i < i_len; ++i){
        std::cin >> a;
        if(i & 1)
            dp[i][1] = std::max(dp[i-1][0], std::max(dp[i-2][1], dp[i-3][0]) + a);
        else{
            dp[i][0] = dp[i-2][0] + a;
            if(i > 4)
                dp[i][2] = std::max(dp[i-1][1], std::max({dp[i-2][2], dp[i-3][1], dp[i-4][0]}) + a);
        }
    }
    std::cout << dp[N+3][(N & 1) + 1] << std::endl;
    return 0;
}
