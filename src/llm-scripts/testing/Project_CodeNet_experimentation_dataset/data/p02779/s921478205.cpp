///////////////////////////////////////////////////////////////////////////
// /*Dis = size of the program || TLE. */
/*
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
*/
// #pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops") /* D = Too many loops */

#include <sys/time.h>  // for CLOCKS_PER_SEC

#include <ctime>     // for clock
#include <iostream>  // for operator<<, ostream, istream, basic_ostream
#include <unordered_set>
using namespace std;
#define endl '\n'
typedef long long ll;

//////////////////////////////////////////////////////////////////////////
/* Custom function starts here */

/* Custom function ends here: */
//////////////////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  /* MAIN Code STARTS here: */
  unordered_set<long long int> ss;
  unordered_set<long long int> dup;
  long n;
  cin >> n;
  for (long i = 0; i < n; i++) {
    ll num;
    cin >> num;
    if (ss.find(num) != ss.end()) {
      dup.insert(num);
    } else {
      ss.insert(num);
    }
  }
  if (dup.empty() == true) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  /* MAIN Code ENDS here: */
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}