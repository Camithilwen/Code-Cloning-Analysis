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
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define sz size()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

ll dp[110][110];

string query(int n){
    cout << n << endl;
    fflush(stdout);
    string res;
    cin >> res;
    if(res == "Vacant")exit(0);
    return res;
}

int main(){
    int n;
    cin >> n;
    int l = 0, r = n - 1;
    string x = query(l);
    string y = query(r);
    while(1){
        int mid = (l + r) / 2;
        string z = query(mid);
        if((z == x) != (l % 2 == mid % 2)){
            r = mid;
            y = z;
        }
        else {
            l = mid;
            x = z;
        }
    }
}