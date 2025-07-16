#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <stdio.h>
#include <unistd.h>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define PI 3.14159265359

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  if (n <= 2) {
    P(n);
    return 0;
  }
  mp[2] = 1;
  for (int i = 3; i <= n; i++) {
    int tmp = i;
    while (tmp != 1) {
      int flag = 1;
      for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (tmp % itr->first == 0) {
          flag = 0;
          tmp /= itr->first;
          itr->second++;
          break;
        }
      }
      if (flag == 1) {
        mp[tmp] = 1;
        tmp /= tmp;
      }
    }
  }
  ll ans = 1;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    ans = (ans * (itr->second + 1)) % mod;
    // cout << itr->first << " => " << itr->second << endl;
  }
  P(ans);
  return 0;
}

