#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define MAX_N 100000

int main(){
  ll n;
  cin >> n;

  cout << 50 << endl;

  ll b = n / 50;
  int a = n % 50;
  ll flag = 0;
  REP(i,50){
    if(i<a){
      flag = 1;
    }else{
      flag = 0;
    }
    cout << i + (b + flag) * 51 - n << ' ';
  }
  cout << endl;

  return 0;
}