#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long

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

void chmaxs(string &s,string ref)
{
  int flg = 0;
  
  if(s == ref)return;

  if(ref.size() != s.size())
  {
    if(ref.size() > s.size())
    {
      s = ref;
      return;
    }
    else
    {
      return;
    }
  }
    

  if(ref.size() == s.size());
  {
    for (int i = 0; i < s.size(); i++)
    {
      if(ref[i] != s[i])
      {
        if(ref[i] > s[i])
        {
          s = ref;
          return;
        }
        else
        {
          return;
        }
        
      }
    }
    
  }
  return;
}


void solve(void)
{
  vector<int> data = {0,2,5,5,4,5,6,3,7,6};
  int N,M; cin>>N; cin>>M;
  vector<int> vec (M,0);
  for (int i = 0; i < M; i++)
  {
     cin>>vec[i];
  }
  vector<string> DP (N+1,"");//i本のマッチを用いて作ることが可能な整数のうち最大のものを格納する。
  for (int i = 1; i <= N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      int fi = i - data[vec[j]];
      if(fi < 0 )continue;
      if(fi != 0 && DP[fi] == "")continue;
      chmaxs(DP[i],DP[fi] + to_string(vec[j]));
    }
    
  }
  cout<<DP[N]<<endl;

  
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
