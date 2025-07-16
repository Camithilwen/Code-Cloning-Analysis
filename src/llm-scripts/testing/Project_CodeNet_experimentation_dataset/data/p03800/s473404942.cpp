#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  string t, s;std::cin >> s;
  //SS

  char end='&';
  char pre = 'S';
  t = "S";
  re(i, s.size()){
    int k = (s[i]=='o'?1:-1);
    if(t[i]=='W') k*=-1;
    int b = ((i==0?pre:t[i-1])=='S'?1:-1);
    if(k==-1) b*=-1;
    if(b==1){
      if(i==s.size()-1){
        end = 'S';
        break;
      }
      t+='S';
    }else {
      if(i==s.size()-1){
        end = 'W';
        break;
      }
      t+='W';
    }
  }
  if(pre==t[n-1]&&t[0]==end){
    std::cout << t << '\n';
    return 0;
  }
  //SW
  pre = 'S';
  t = "W";
  re(i, s.size()){
    int k = (s[i]=='o'?1:-1);
    if(t[i]=='W') k*=-1;
    int b = ((i==0?pre:t[i-1])=='S'?1:-1);
    if(k==-1) b*=-1;
    if(b==1){
      if(i==s.size()-1){
        end = 'S';
        break;
      }
      t+='S';
    }else {
      if(i==s.size()-1){
        end = 'W';
        break;
      }
      t+='W';
    }
  }
  if(pre==t[n-1]&&t[0]==end){
    std::cout << t << '\n';
    return 0;
  }
  //WW
  pre = 'W';
  t = "W";
  re(i, s.size()){
    int k = (s[i]=='o'?1:-1);
    if(t[i]=='W') k*=-1;
    int b = ((i==0?pre:t[i-1])=='S'?1:-1);
    if(k==-1) b*=-1;
    if(b==1){
      if(i==s.size()-1){
        end = 'S';
        break;
      }
      t+='S';
    }else {
      if(i==s.size()-1){
        end = 'W';
        break;
      }
      t+='W';
    }
  }
  if(pre==t[n-1]&&t[0]==end){
    std::cout << t << '\n';
    return 0;
  }
  //WS
  pre = 'W';
  t = "S";
  re(i, s.size()){
    int k = (s[i]=='o'?1:-1);
    if(t[i]=='W') k*=-1;
    int b = ((i==0?pre:t[i-1])=='S'?1:-1);
    if(k==-1) b*=-1;
    if(b==1){
      if(i==s.size()-1){
        end = 'S';
        break;
      }
      t+='S';
    }else {
      if(i==s.size()-1){
        end = 'W';
        break;
      }
      t+='W';
    }
  }
  if(pre==t[n-1]&&t[0]==end){
    std::cout << t << '\n';
    return 0;
  }
  std::cout << -1 << '\n';
  return 0;
}
