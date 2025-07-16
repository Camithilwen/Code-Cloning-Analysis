#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

int N, M, Q;
const int MAX_NM = 2000;
const int MAX_Q = 200000;
string S[MAX_NM];
int X1[MAX_Q], Y1[MAX_Q], X2[MAX_Q], Y2[MAX_Q];

int main(){
  cin >> N >> M >> Q;
  REP(i, N) cin >> S[i];
  REP(i, Q) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  REP(i, Q) {
    X1[i]--;
    Y1[i]--;
    X2[i]--;
    Y2[i]--;
  }

  int blue[N][M], vert[N][M], hori[N][M];
  REP(i, N) REP(j, M) {
    blue[i][j] = 0;
    vert[i][j] = 0;
    hori[i][j] = 0;
  }

  REP(i, N) {
    REP(j, M) {
      if(i > 0) {
        blue[i][j] += blue[i - 1][j];
        vert[i][j] += vert[i - 1][j];
        hori[i][j] += hori[i - 1][j];
      }
      if(j > 0) {
        blue[i][j] += blue[i][j - 1];
        vert[i][j] += vert[i][j - 1];
        hori[i][j] += hori[i][j - 1];
      }
      if(i > 0 && j > 0) {
        blue[i][j] -= blue[i - 1][j - 1];
        vert[i][j] -= vert[i - 1][j - 1];
        hori[i][j] -= hori[i - 1][j - 1];
      }
      if(S[i][j] == '1') {
        blue[i][j]++;
        if(i > 0 && S[i - 1][j] == '1') vert[i][j]++;
        if(j > 0 && S[i][j - 1] == '1') hori[i][j]++;
      }
    }
  }

  REP(i, Q) {
    ll ans = 0;
    ll b = 0, v = 0, h = 0;
    b += blue[X2[i]][Y2[i]];
    v += vert[X2[i]][Y2[i]];
    h += hori[X2[i]][Y2[i]];
    if(X1[i] > 0) {
      b -= blue[X1[i] - 1][Y2[i]];
      v -= vert[X1[i]][Y2[i]];
      h -= hori[X1[i] - 1][Y2[i]];
    }
    if(Y1[i] > 0) {
      b -= blue[X2[i]][Y1[i] - 1];
      v -= vert[X2[i]][Y1[i] - 1];
      h -= hori[X2[i]][Y1[i]];
    }
    if(X1[i] > 0 && Y1[i] > 0) {
      b += blue[X1[i] - 1][Y1[i] - 1];
      v += vert[X1[i]][Y1[i] - 1];
      h += hori[X1[i] - 1][Y1[i]];
    }
    cout << b - v - h << endl;
  }

  return 0;
}

