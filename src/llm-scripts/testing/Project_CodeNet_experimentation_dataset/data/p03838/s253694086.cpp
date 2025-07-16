#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll A,B;
  cin >> A >> B;

  if(A<B){
    if(abs(A)==abs(B)){
      cout << 1 << endl;
    }else if(abs(A)<abs(B)){
      if(A>=0){
        cout << B-A << endl;
      }else{
        cout << B+A+1 << endl;
      }
    }else{
      if(B>0){
        cout << -A-B+1 << endl;
      }else{
        cout << B-A << endl;
      }
    }
  }else{
    if(abs(A)==abs(B)){
      cout << 1 << endl;
    }else if(abs(A)<abs(B)){
      if(A>=0){
        cout << -B-A+1 << endl;
      }else{
        cout << A-B+2 << endl;
      }
    }else{
      if(B<=0){
        cout << B+A+1 << endl;
      }else{
        cout << A-B+2 << endl;
      }
    }
  }
}