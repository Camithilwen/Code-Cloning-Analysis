/* Simplicity and Goodness */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B) { cout << ' ' << A; my_dbg(B...); }
#define dbg(...)  cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", (int)(n))
#define prin(n) printf("%d\n", (int)(n))
#define lpri(n) printf("%lld ", n)
#define lprin(n) printf("%lld\n", n)
#define rep(i,a,b) for(int i=a; i<(int)b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9+7;
const int maxN = 1e6+2;


int main()
{
   string s;
   cin >> s;

   int l = -2, r = -2;

   for(int i = 0; i + 1 < (int) s.size(); i ++) {
      if(s[i] == s[i + 1]) {
         l = i, r = i + 1;
         break;
      }
   }

   for(int i = 0; i + 2 < (int) s.size(); i ++) {
      set<char> unique;
      for(int j = i; j < i + 3; j ++) {
         unique.insert(s[j]);
      }
      if((int) unique.size() <= 2) {
         l = i, r = i + 2;
         break;
      }
   }

   printf("%d %d\n", l + 1, r + 1);
}