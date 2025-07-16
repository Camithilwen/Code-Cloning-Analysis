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
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int main(){
  int N, M, A[1024], c[1024];
  scanf("%d%d", &N, &M);
  memset(c, 0, sizeof(c));

  rep(i, N) scanf("%d", A+i);
  rep(i, M){
    int B;
    scanf("%d", &B);
    int p = 0;
    rep(j, N) if(B >= A[j]){ p = j; break;}
    c[p]++;
  }
  //      cout << "ok\n";      
  int res =0;
  rep(i, N) if(c[res] <= c[i]) res = i;
  printf("%d\n", res+1);
  return 0;
}