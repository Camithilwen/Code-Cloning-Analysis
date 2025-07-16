#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;
using pii=pair<int,int>;



int main() {
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  int dx=tx-sx,dy=ty-sy;
  string ans="";
  string right(dx,'R'),left(dx,'L'),up(dy,'U'),down(dy,'D');
  ans=ans+up+right+down+left+'L'+up+'U'+'R'+right+'D'+'R'+down+'D'+'L'+left+'U';
  cout<<ans<<endl;

  return 0;
}