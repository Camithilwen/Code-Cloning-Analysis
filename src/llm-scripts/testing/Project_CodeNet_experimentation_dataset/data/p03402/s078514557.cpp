#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int MAXH = 100;
const int MAXW = 100;

int main() {
  
  int a, b;
  cin >> a >> b;
  vector<string> s(MAXH);
  rep(i, MAXH / 2) {
    s[i] = string(MAXW, '#');
  }
  for (int i = MAXH / 2; i < MAXH; ++i) {
    s[i] = string(MAXW, '.');
  }
  a--; b--;

  int cur = 0;
  rep(i, a) {
    if(cur % 200 == 100) cur += 100;
    s[cur / MAXW][cur % MAXW] = '.';
    cur += 2;
    
  }
  cur = 50 * 100 + 100;
  rep(i, b) {
    if(cur % 200 == 100) cur += 100;
    s[cur / MAXW][cur % MAXW] = '#';
    cur += 2;
    
  }
  cout << MAXH << " " << MAXW << endl;
  rep(i, MAXH) cout << s[i] << endl;
}