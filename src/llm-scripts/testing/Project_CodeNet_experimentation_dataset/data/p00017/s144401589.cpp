// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve

int main(int argc, char const* argv[])
{
  string s;
  while(getline(cin, s)){
    FOR(i, 1, 27){
      string t = s;
      string res = "";
      rep(j, t.size()){
        if(!('a' <= s[j] && s[j] <= 'z')){
          res += t[j];
        }else{
          res += char(((int(t[j] - 'a') + i) % 26) + 'a');
        }
      }
      string tmp = "";
      bool flag = false;
      rep(j, res.size()){
        if(res[j] != ' ' && res[j] != '.')tmp += res[j];
        else{
          if(tmp == "the" || tmp == "this" || tmp == "that"){
            flag = true;
            break;
          }
          tmp = "";
        }
      }
      if(tmp == "the" || tmp == "this" || tmp == "that"){
        flag = true;
      }
      if(flag){
        cout << res << endl;
        break;
      }
    }
  }
	return 0;
}

