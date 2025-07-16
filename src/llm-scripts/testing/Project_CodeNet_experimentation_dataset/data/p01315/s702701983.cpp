//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  while(cin >> N, N){
	vector< pair<double,string> > k;
	REP(i,N){
	  string L; int P, A, B, C, D, E, F, S, M;
	  cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;
	  int tot = A + B + C + D + E + (M - 1)*(D + E);
	  int pr = F * S * M - P;
	  k.PB(MP(pr*1.0/tot, L));
	}
	sort(ALL(k), [](const pair<double,string>& p1, const pair<double,string>& p2)->bool{
		return p1.first > p2.first || (abs(p1.first-p2.first) < EPS
									   && p1.second < p2.second);
	  });
	REP(i,N)
	  cout << k[i].second << endl;
	cout << "#" << endl;
  }
  
  return 0;
}