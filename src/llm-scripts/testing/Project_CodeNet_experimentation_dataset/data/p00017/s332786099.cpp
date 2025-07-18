#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}

int main() {
  string s;
  while (getline(cin, s)) {
    string orig;
    for (int i = 0; i <= 'z'-'a'; i++) {
      orig = s;
      for (int j = 0; j < orig.size(); j++) {
        if (orig[j] >= 'a' && orig[j] <= 'z') {
          orig[j] = 'a' + ((orig[j]-'a') + i) % ('z'-'a'+1);
        }
      }
      if (orig.find("the") != string::npos ||
          orig.find("this") != string::npos ||
          orig.find("that") != string::npos) {
        break;
      }
    }
    cout << orig << endl;
  }
}