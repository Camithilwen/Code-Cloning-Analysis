#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

string dp[20000];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int cost[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    rep(i, m)cin >> a[i];

    rep(i, n + 100)dp[i] = "-";
    dp[0] = "";

    rep(i, n){
        if(dp[i] == "-")continue;
        for(int now : a){
            if(dp[i + cost[now]].size() == dp[i].size() + 1){
                if(dp[i + cost[now]] < dp[i] + to_string(now))dp[i + cost[now]] = dp[i] + to_string(now);
            }
            else if(dp[i + cost[now]].size() < dp[i].size() + 1)dp[i + cost[now]] = dp[i] + to_string(now);
        }
    }
    cout << dp[n] << endl;
}

