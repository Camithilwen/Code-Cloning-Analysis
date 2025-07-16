#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <unordered_set>
 
#define YesNo(b) ((b) ? "Yes" : "No")
#define YESNO(b) ((b) ? "YES" : "NO")

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

template<template<class...> class ContT, class ValueT, size_t Dim>
struct vec_type
{
    using type = ContT<typename vec_type<ContT, ValueT, Dim-1>::type>;
};

template<template<class...> class ContT, class ValueT>
struct vec_type<ContT, ValueT, 0>
{
    using type = ValueT;
};

template<class ValueT, size_t Dim>
using vec_t = typename vec_type<std::vector, ValueT, Dim>::type;


template<class ValueT, size_t Dim, class = typename std::enable_if<Dim == 0>::type>
auto make_vec(ValueT value = ValueT()) -> ValueT
{
    return value;
}

template<class ValueT, size_t Dim, class... Rest>
auto make_vec(size_t size0, Rest... rest)
{
    auto vec = make_vec<ValueT, Dim-1>(rest...);
    return std::vector(size0, vec);
}



int diffabs(int l, int r)
{
    if (l < r) return r-l;
    else return l-r;    
}

int iabs(int i)
{
    if (i > 0) return i;
    else return -i;
}


int main()
{
    int H, W;
    cin >> H >> W;

    vec_t<int,2> A = make_vec<int,2>(H, W);
    vec_t<int,2> B = make_vec<int,2>(H, W);

    for (int h = 0; h < H; ++h)
        for (int w = 0; w < W; ++w)
            cin >> A[h][w];

    for (int h = 0; h < H; ++h)
        for (int w = 0; w < W; ++w)
            cin >> B[h][w];
   

    vec_t<bool,3> dp = make_vec<bool,3>(H, W, (H+W)*80, false);

    for (int h = 0; h < H; ++h)
    {
        for (int w = 0; w < W; ++w)
        {
            int d = diffabs(A[h][w], B[h][w]);
            if (h == 0 && w == 0)
            {
                dp[h][w][d] = true;
            }
            
            if (w > 0)
            {
                for (size_t i = 0; i < dp[h][w-1].size(); ++i)
                {
                    if (dp[h][w-1][i])
                    {
                        dp[h][w][i+d] = true;
                        dp[h][w][iabs(i-d)] = true;
                    }
                }
            }

            if (h > 0)
            {
                for (size_t i = 0; i < dp[h-1][w].size(); ++i)
                {
                    if (dp[h-1][w][i])
                    {
                        dp[h][w][i+d] = true;
                        dp[h][w][iabs(i-d)] = true;
                    }
                }
            }
        }
    }

    const auto &hw = dp[H-1][W-1];
    auto it = find_if(begin(hw), end(hw), [](auto b){ return b; });
    int ans = std::distance(begin(hw), it);
    cout << ans << endl;
}