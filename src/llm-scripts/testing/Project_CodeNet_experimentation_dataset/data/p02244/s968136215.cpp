#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#define MAX 10000
#define INFTY 1<<30 // 2^30
#define N 8
using namespace std;
typedef long long llong;
static const int NIL = -1;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

static const int NOT_FREE = 0;
static const int FREE = 1;
static const int FIXED = 2;

bool X[N][N];
vector<pair<int, int> > ans;

void init()
{
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      X[i][j] = false;
}

bool can_pos(int x, int y)
{
  for(int i = 0; i < ans.size(); i++)
  {
    int tx = ans[i].first;
    int ty = ans[i].second;
    if(x == tx) return false;
    if(y == ty) return false;
    if((x-tx)*(x-tx) == (y-ty)*(y-ty)) return false;
  }
  return true;
}

void printBoard()
{
  for(int i = 0; i < ans.size(); i++)
    X[ans[i].first][ans[i].second] = true;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
      cout << (X[i][j] ? "Q" : ".");
    cout << endl;
  }
}

bool recursive(int p)
{
  for(; p < N * N; p++)
  {
    int i = p%N;
    int j = p/N;
    if(!(can_pos(i,j))) continue;
    pair<int, int>tmp = make_pair(i, j);
    ans.push_back(tmp);
    if(!recursive((j+1)*N)) ans.pop_back();
  }
  if(ans.size() == N) return true;
  return false;
}

int main()
{
  init();
  int k, r, c; cin >> k;
  for(int i = 0; i < k; i++)
  {
    cin >> r >> c;
    pair<int, int> tmp = make_pair(r, c);
    ans.push_back(tmp);
  }
  if(recursive(0)) printBoard();
  return 0;
}