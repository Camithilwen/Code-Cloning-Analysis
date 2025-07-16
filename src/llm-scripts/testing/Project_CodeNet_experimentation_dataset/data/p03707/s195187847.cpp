#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
int f[N][N];
int tot[N][N];
int up[N][N];
int lef[N][N];

int tqr(int il, int jl, int ir, int jr){
  if(il > ir || jl > jr) return 0;
  return tot[ir][jr] - tot[ir][jl - 1] - tot[il - 1][jr] + tot[il-1][jl-1];
}

int uqr(int il, int jl, int ir, int jr){
  if(il > ir || jl > jr) return 0;
  return up[ir][jr] - up[ir][jl - 1] - up[il - 1][jr] + up[il-1][jl-1];
}

int lqr(int il, int jl, int ir, int jr){
  if(il > ir || jl > jr) return 0;
  return lef[ir][jr] - lef[ir][jl - 1] - lef[il - 1][jr] + lef[il-1][jl-1];
}

int main(){
  fastIO;
  int n, m, q;
  cin >> n >> m >> q;
  char k;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> k;
      f[i][j] = k - '0';
      tot[i][j] = f[i][j] + tot[i-1][j] + tot[i][j-1] - tot[i-1][j-1];
      up[i][j] = (f[i][j] & f[i-1][j]) + up[i-1][j] + up[i][j-1] - up[i-1][j-1];
      lef[i][j] = (f[i][j] & f[i][j-1]) + lef[i-1][j] + lef[i][j-1] - lef[i-1][j-1];
    }
  }
  int ci, cj, ri, rj;
  for(int i = 0 ; i < q; i ++ ){
    cin >> ci >> cj >> ri >> rj;
    cout << tqr(ci, cj, ri, rj) - uqr(ci + 1, cj, ri, rj) - lqr(ci, cj + 1, ri, rj) << "\n";
  }
  return 0;
}
