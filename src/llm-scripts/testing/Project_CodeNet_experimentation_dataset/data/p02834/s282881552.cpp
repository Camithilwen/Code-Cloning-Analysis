//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second
#define mp make_pair
 
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

int N, U, V;
vector <int> Graph[int(1e5 + 5)];
int DistT[int(1e5 + 5)], DistA[int(1e5 + 5)];

int Prepare(){
  scanf("%d%d%d", &N, &U, &V);
  fill(DistT, DistT + N + 1, -1);
  fill(DistA, DistA + N + 1, -1);
  for (int i = 0; i < N - 1; i++){
    int A, B; scanf("%d%d", &A, &B);
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }
  return 0;
}

int BFS(){
  queue <int> que;
  que.push(U); DistT[U] = 0;
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int i = 0; i < Graph[Q].size(); i++){
      int next = Graph[Q][i];
      if (DistT[next] != -1) continue;
      DistT[next] = DistT[Q] + 1;
      que.push(next);
    }
  }
  que.push(V); DistA[V] = 0;
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int i = 0; i < Graph[Q].size(); i++){
      int next = Graph[Q][i];
      if (DistA[next] != -1) continue;
      DistA[next] = DistA[Q] + 1;
      que.push(next);
    }
  }
  return 0;
}

int main(){
  Prepare(); BFS();

  int ans = 0;
  for (int i = 1; i <= N; i++){
    if (DistA[i] >= DistA[U] && DistT[i] < DistA[i]){
      ans = max(ans, DistA[i] - 1);
    }
  }
  cout << ans << endl;

  return 0;
}
