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
#define MEM_SIZE 1000100
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()


template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }


void solve(void)
{
  int n;cin>>n;
  vector<int> vec (n,0);
  for (int i = 0; i < n; i++)
  {
    cin>>vec[i];
    if(i != 0)
    vec[i] += vec[i-1];
  }
  int i1 = 0;
  int i2 = 1;
  int i3 = 2;
  int res = INF;
  while(i2 < n-2)
  {
    while(i1 < i2 - 1)
    {
      if(abs(vec[i1] - (vec[i2] - vec[i1])) > abs(vec[i1+1] - (vec[i2] - vec[i1+1])) )
      i1 ++;
      else
      {
        break;
      }
    }

    while(i3 < n - 2)
    {
      if(abs(vec[n-1] - vec[i3] - (vec[i3] - vec[i2])) >abs(vec[n-1] - vec[i3+1] - (vec[i3+1] - vec[i2])) )
      i3 ++;
      else
      {
        break;
      }
    }
    int p1 = vec[i1];
    int p2 = vec[i2] - vec[i1];
    int p3 = vec[i3] - vec[i2];
    int p4 = vec[n-1] - vec[i3];
    int m1 = max(max(p1,p2),max(p3,p4));
    int m2 = min(min(p1,p2),min(p3,p4));
    chmin(res,m1 - m2);
    i2++;
  }
  cout<<res<<endl;

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
