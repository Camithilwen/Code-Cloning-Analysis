#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include<limits.h>
#include<float.h>
#include<list>
#include <array>
#include <complex>
#include<stdio.h>
#include<string.h>
#include <bitset>

using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
//SOLVE

//-----CODE------//
void DFS(int V,vector<vector<int> > &GRAPH,vector<int> & visited,vector<vector<char> > & mat,int & nB,int &nW,int WIDTH)
{
  if(mat[V/WIDTH][V%WIDTH] == '.')nW++;
  else nB++;
  visited[V] = 1;
  for (auto &&nV : GRAPH[V])
  {
    if(visited[nV] == 1)continue;
    DFS(nV,GRAPH,visited,mat,nB,nW,WIDTH);
  }
  return;
}
//-----CODE------//
void solve(void)
{ 
  int H,W; cin>>H; cin>>W; 
  vector<vector<char> >  mat (H,vector<char>(W,0));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
       cin>>mat[i][j];
    }
  }
  int N = H*W;
  vector<vector<int> > GRAPH (H*W);
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if(i != 0)
      {
        if(mat[i][j] != mat[i-1][j])
        {
          int V = i*W + j;
          int nV = (i-1)*W+j;
          GRAPH[V].emplace_back(nV);
          GRAPH[nV].emplace_back(V);
        }
      }
      if(i != H - 1)
      {
        if(mat[i][j] != mat[i+1][j])
        {
          int V = i*W + j;
          int nV = (i+1)*W+j;
          GRAPH[V].emplace_back(nV);
          GRAPH[nV].emplace_back(V);
        }
      }
      if(j != 0)
      {
        if(mat[i][j] != mat[i][j-1])
        {
          int V = i*W + j;
          int nV = (i)*W+j-1;
          GRAPH[V].emplace_back(nV);
          GRAPH[nV].emplace_back(V);
        }
      }
      if(j != W -1)
      {
        if(mat[i][j] != mat[i][j+1])
        {
          int V = i*W + j;
          int nV = (i)*W+j+1;
          GRAPH[V].emplace_back(nV);
          GRAPH[nV].emplace_back(V);
        }
      }

    }

  }
  vector<int> visited (H*W,-1);
  int ANS = 0;
  for (int i = 0; i < H*W; i++)
  {
    int V = i;
    int nB = 0;
    int nW = 0;
    DFS(V,GRAPH,visited,mat,nB,nW,W);
    ANS += nB * nW;
  }
  cout<<ANS<<endl;
  
  
  return;
}
int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(9);
  solve();

  return 0;
}
