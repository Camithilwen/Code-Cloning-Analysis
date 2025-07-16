

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>


#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s

typedef long long ll;

using namespace std;

long long gcd(long long a, long long b) { 
    if (a == 0)  {   return b;  }
    return gcd(b % a, a); 
};

class Factorial {
    public:
      ll modd = 1000 * 1000 * 1000 + 7;
      vector<ll> bin;

      Factorial(int n) : bin(n+1, 0) {
          bin[0] = 1;
          forr(i,1,n) {
              bin[i] = i*bin[i-1]; bin[i] = bin[i] % modd;
          }
      }

      ll val(int i) {  return bin[i];  }
};


int main()   {
    cout.precision(17);
    ll modd = 1000 * 1000 * 1000 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
    ll infinit = 10000000000000000;


//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);
        readstring(s);
        ll ret = 1;
        ll continuing_intervals = 0;
        forr(i,0,s.size()) {
            bool need_one = (s[i] == 'B');
            if (need_one == continuing_intervals % 2) {
                ret *= continuing_intervals;
                ret = ret % modd;
                continuing_intervals--;
                if (continuing_intervals < 0) { ret = 0; break;  }
            } else {
                continuing_intervals++;
            }
        }
        if (continuing_intervals != 0) {ret = 0;}
        Factorial fa(n+1);
        ret *= fa.val(n); ret = ret % modd;
        
        cout << ret << endl;
    }
    return 0;
}
