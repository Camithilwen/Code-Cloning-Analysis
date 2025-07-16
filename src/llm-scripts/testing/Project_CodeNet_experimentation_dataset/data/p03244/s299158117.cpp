#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n), o(100001,0), e(100001,0);
    rep(i,n){
        std::cin >> v[i];
        if(i%2) o[v[i]]++;
        else e[v[i]]++;
    }

    auto io = std::distance(o.begin(),std::max_element(o.begin(),o.end()));
    auto ie = std::distance(e.begin(),std::max_element(e.begin(),e.end()));

    std::sort(o.begin(),o.end());
    std::sort(e.begin(),e.end());
    int ans = 0;
    if(io==ie){ //最大の値が同じとき
        ans = std::min(n-o[o.size()-1]-e[e.size()-2],n-o[o.size()-2]-e[e.size()-1]);
    }else{ //最大の値が違うとき
        ans = n - o.back() - e.back();
    }
    std::cout << ans << "\n";
    return 0;
}
