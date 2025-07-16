
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
// #include<assert.h>
#include<random>
using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
#define MEM_SIZE 100010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

//https://www.youtube.com/watch?v=RDaGj_ztNz4&feature=youtu.be

//-----CODE------//

int dfs(int v,int c,vector<vector<int> > & GRAPH,vector<int> & color)
{

  color[v] = c;
  // DEBUG(color);
  for (auto &&u : GRAPH[v])
  {
    if(color[u] == c)
    {
      return false;
    }
    
    if(color[u] ==0 && !dfs(u,-1*c,GRAPH,color))
    {
    return false;
    }
  }
  return true;
  
}
void solve(void)
{
  int n,m;
  cin>>n>>m;
  vector<vector<int> > GRAPH (n);
  for (int i = 0; i < m; i++)
  {
    int A,B;
    cin>>A>>B;
    A--;B--;
    GRAPH[A].push_back(B);
    GRAPH[B].push_back(A);
  }
  int b = 0,w = 0;
  vector<int> color(n,0);
  if(dfs(0,1,GRAPH,color))
  {
    for (int i = 0; i < n; i++)
    {
      if(color[i] == 1)
      {
        b++;
      }
      else if(color[i] == -1)
      {
        w++;
      }
    }
    cout<<b*w - m <<endl;
    
  }
  else
  {
    cout<<n*(n-1)/2 - m<<endl;
  }
  


  

  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
