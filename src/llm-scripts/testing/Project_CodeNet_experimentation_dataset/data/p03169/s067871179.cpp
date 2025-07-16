#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip> 

using ll = long long;
using ull = unsigned long long;
using namespace std;

#define FALSE printf("false\n");
#define TRUE printf("true\n");
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i = 0;(i) < ((int)(n));++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define test(a) cout<<"line:"<<__LINE__<<"["<<(#a)<<": "<<(a)<<"]"<<endl

const int INF = 1e9+7;
const ll INFL = 9*1e18;

// const int dx[4] = { 1, 0, -1, 0 };
// const int dy[4] = { 0, 1, 0, -1 };

const int dx[8] = {1, 1, 0,-1,-1,-1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0,-1,-1,-1};

ll inline digit(ll num){int tmp = 0;while(num){tmp++;num/=10;}return tmp;} // 桁数
template<typename T>inline T SUM(vector<T> vec){return accumulate(all(vec),(T)0);} // vectorの中身を全部足す
template<typename T>inline T digitSum(T num){T sum = 0;while(num){sum+=num%10;num/=10;}return sum;} // 各桁の和
template<typename T>inline T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);} // 最大公約数
template<typename T>inline T lcm(T a, T b){T g = gcd(a,b);return a/g*b;} // 最小公倍数
template<typename T>inline T power(T a,T b){T tmp=1;rep(i,b){tmp*=a;}return tmp;} // 累乗
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>inline void print(T&& x){cout<<setprecision(32)<<x<<endl;}// 改行付き出力



double dp[330][330][330];
bool flag[330][330][330];
int n;
 
double recurse(int i, int j, int k)
{
    if (abs(dp[i][j][k] + 1) > 1e-9)
        return dp[i][j][k];
    
    double ret = 0;
    ret += (double)n / (double)(i + j + k);
 
    if (i > 0)
        ret += (double)i / (double)(i + j + k) * recurse(i - 1, j, k);
    if (j > 0)
        ret += (double)j / (double)(i + j + k) * recurse(i + 1, j - 1, k);
    if (k > 0)
        ret += (double)k / (double)(i + j + k) * recurse(i, j + 1, k - 1);
    dp[i][j][k] = ret;
 
    return ret;
}
// TODO: write
int main() {
  cin>>n;
  int c[4] = {0};
  rep(i,n){
    int a;cin>>a;
    c[a]++;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  print(recurse(c[1],c[2],c[3]));
  return 0;
}