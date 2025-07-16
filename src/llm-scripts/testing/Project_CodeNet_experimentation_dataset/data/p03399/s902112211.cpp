/**
 * auther: moririn_cocoa
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define ll long long
#define pll pair<ll,ll>
#define pq priority_queue
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

int main(int argc, const char * argv[]) {
  
  int A;
  int B;
  int C;
  int D;
  
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> D;
  
  cout << min ( A,B ) + min ( C,D ) << endl;
  
  return 0;
}
