#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
int p[3];
void judge(){
  REP(j,3){
    if(p[j]==100){
      cout<<"A"<<endl;
      return;
    }
  }
  if(p[0]+p[1]>=180){
    cout<<"A"<<endl;
    return;
  }
  int sum=0;
  REP(j,3)sum+=p[j];
  if(sum>=240){
    cout<<"A"<<endl;
    return ;
  }
  if(sum>=210){
    cout<<"B"<<endl;
    return ;
  }
  if(sum>=150&&(p[0]>=80||p[1]>=80)){
    cout<<"B"<<endl;
    return ;
  }
  cout<<"C"<<endl;
}
int main(void){
  int n;
  while(cin>>n){
    if(n==0) break;
    REP(i,n){
      REP(j,3)cin>>p[j];
      judge();
    }
  }

  return 0;
}