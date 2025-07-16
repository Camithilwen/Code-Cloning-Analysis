#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 200007;
const int MAX2 = 1000007;
const int LEN = 21;
const int BASE = 1000000000;

const int MOD = 998244353;

int n;
int C[MAX];

int main()
{
  cin >> n;
  FOR (i,0,n)
  {
    int x;
    scanf("%d", &x);
    C[x] ++;

    if (i == 0 && x != 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }

  int tot = 1;

  if (C[0] != 1)
  {
    cout << 0 << endl;
    return 0;
  }
  
  Int res = 1;

  FOR (i,1,n)
    FOR (j,0,C[i])
      res = res * C[i-1] % MOD;


  cout << res << endl;

  






 
  return 0;
}
