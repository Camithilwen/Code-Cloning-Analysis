#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define ull unsigned long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define FOR(i,start,stop)  for(int i=(start); i < (stop); i++)
#define FORD(i,start,stop) for(int i=(start); i >= (stop); i--)
#define RIP(i,stop) FOR(i,0,stop)
#define PI 3.141592653589793
#define PRECISION(c,f) fixed << setprecision(c) << f
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int X; 
  cin >> X;

  int ans=0;
  while(true){
    if(X-500 < 0) break;
    X -= 500;
    ans += 1000;
  }
  //cout << X << endl;
  while(true){
    if(X-5 < 0) break;
    X -= 5;
    ans += 5;
  }

  cout << ans << endl;

  return 0;
}
