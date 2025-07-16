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
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
//const ll MOD = INF + 7;
//Combination MOD
const int MOD = 1e9 + 7;



int main(){
   int n;
   cin >> n;
   vector<int> a(n), b(n);
   vector<P> sum(n);
   rep(i, n){
      cin >> a[i] >> b[i];
      sum[i] = P(a[i] + b[i], i);
   }
   sort(ALL(sum), greater<P>());
   ll taka = 0, aok = 0;
   rep(i, n){
     //cout << sum[i].first << " " << sum[i].second << endl;
      if(i % 2 == 0){
         taka += a[sum[i].second];
      }
      else aok += b[sum[i].second];
   }
   cout << (ll)(taka - aok) << endl;
}
