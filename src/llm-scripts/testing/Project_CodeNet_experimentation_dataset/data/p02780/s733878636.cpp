#include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
#include <fstream>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  // ll INF = INT_MAX;
  // ll mod = 1000000007;
  // lld PI = 3.141592653;
 
// const int N = 2e5 + 5;


  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      // ifstream cin("input.txt");

     int n,k;
     cin>>n>>k;
     vector<int> a(n);
     for (int i = 0;i<n;i++) cin>>a[i];
      vector<ll> pref(n);
   
    pref[0] = a[0];
    for (int i = 1;i<n;i++) pref[i] = pref[i-1] + a[i];
       lld ans = lld((k+pref[k-1]))/2;
    for (int i = k;i<n;i++){
      ll sum = pref[i] - pref[i-k];
      ans = max(ans, (lld(k)+sum)/2);
    }
cout<<setprecision(20)<<ans<<"\n";
}