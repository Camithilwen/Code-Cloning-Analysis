#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int H, W;
char C[405][405];
bool visited[405][405];
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
ll ans = 0, b = 0, w = 0;

int Solve(int i, int j){
  b = 0; w = 0;
  if (C[i][j] == '.') w++;
  else b++;
  visited[i][j] = true;

  queue <Pii> que; que.push({i, j});
  while (!que.empty()){
    Pii Q = que.front(); que.pop();
    for (int k = 0; k < 4; k++){
      int I = Q.fi + di[k], J = Q.se + dj[k];
      if (0 <= I && I < H && 0 <= J && J < W){
        if (visited[I][J]) continue;
        if (C[I][J] == C[Q.fi][Q.se]) continue;
        
        que.push({I, J});
        visited[I][J] = true;
        if (C[I][J] == '.') w++;
        else b++;
      }
    }
  }

  ans += b * w;
  return 0;
}


int main(){
  cin >> H >> W;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> C[i][j];
    }
  }

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (!visited[i][j]) Solve(i, j);
    }
  }
  cout << ans << endl;

  return 0;
}
