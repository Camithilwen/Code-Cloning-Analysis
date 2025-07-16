#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define rrev(i, m, n) for(int (i)=(n)-1; (i)>=(m); (i)--)
#define erev(i, m, n) for(int (i)=(n); (i)>=(m); (i)--)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T, class S> inline bool minup(T& m, S x){ return m>(T)x ? (m=(T)x, true) : false; }
template<class T, class S> inline bool maxup(T& m, S x){ return m<(T)x ? (m=(T)x, true) : false; }

const int    INF = 1000000000;
const ll     MOD = 1000000007LL;
const double EPS = 1E-12;

const int MAX_N = 13;
const int n = MAX_N;
const int m = 5;
int card[MAX_N];
vi x(m);

string judge(vi num)
{
  if(num[0] == 4) return "four card";
  if(num[0] == 3 && num[1] == 2) return "full house" ;
  if(num[0] == 1 && x[4] - x[0] == 4) return "straight";
  if(num[0] == 1 && x[0] == 0 && x[1] == 9 && x[4] == 12) return "straight";
  if(num[0] == 3) return "three card";
  if(num[0] == 2 && num[1] == 2) return "two pair";
  if(num[0] == 2) return "one pair";
  return "null";
}

int main()
{
  rep(i, n) card[i] = i;

  while(~scanf("%d,%d,%d,%d,%d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5])){
    vi num(MAX_N);
    rep(i, m) x[i] -= 1;
    rep(i, m) num[x[i]] += 1;
    sort(ALL(num), greater<int>());
    sort(ALL(x));
    cout << judge(num) << endl;
  }

  return 0;
}