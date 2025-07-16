#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n) 
bool primecheck(int n){
  FOR(i,2,n/2)
    if(n%i == 0) return false;
  return true;
}


int main(void){
  int twinprime[1000] = {0};
  int ptr=0;
  FOR(i,3,9999){
    if(primecheck(i)&&primecheck(i+2))
      twinprime[ptr++] = i;
  }
  twinprime[ptr] = 10001;
  int n;
  while(cin>>n,n){
    int i=0;
    while(true){
      if(twinprime[i]+2>n){
        cout << twinprime[i-1] << " " << twinprime[i-1] + 2<< endl;
        break;
      }
      i++;
    }
  }
}