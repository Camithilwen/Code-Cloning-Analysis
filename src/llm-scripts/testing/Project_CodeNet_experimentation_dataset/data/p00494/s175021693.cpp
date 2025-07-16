#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

char s[1000001];

int main(){

  fgets(s, sizeof(s), stdin);
  int res = 0, oc, ic, jc;
  int i, j, k, l;
  int slen = strlen(s);
  jc = oc = ic = 0;
  rep(i, slen){
    if(ic == 0 && oc == 0 && s[i] == 'J') jc++;
    else if(jc && ic == 0 && s[i] == 'O') oc++;
    else if(jc && oc && s[i] == 'I') ic++;
    else{
      if(jc >= oc && ic >= oc) res = max(res, oc);
      jc = oc = ic = 0;
      if(s[i] == 'J') jc++;
    }
  }

  if(jc >= oc && ic >= oc) res = max(res, oc);
  printf("%d\n", res);
  return 0;
}