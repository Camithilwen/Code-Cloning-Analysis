#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <complex>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
const double PI = 3.141592653589793238462643383279502884L;
const int LARGE_PRIME = 1000000007;
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define rtr(c, i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define repfn(i,a,cont,next) \
  for(auto i = (a); [=](){return(cont);}(); i = [=](){return(next);}())
#define repby(i,a,b,s) repfn(i,a,i<b,i+s)
#define repab(i,a,b) repby(i,a,b,1)
#define rep(i,b) repab(i,0,b)
#define pb push_back
#define sz(c) int((c).size())

char rot13(char c, int n)
{
  return 'a' + (c + n) % 26;
}

string rot13(string &s, int n)
{
  n %= 26;
  string res;
  tr (s, p) {
    if (islower(*p))
      res.pb(rot13(*p, n));
    else
      res.pb(*p);
  }
  return res;
}

int main(int argc, char **argv)
{
  string enc;

  while (!getline(cin, enc).eof()) {
    for (int i = 0; i < 26; i++) {
      string s = rot13(enc, i);
      if ((int)s.find("the ") >= 0 || (int)s.find("this ") >= 0 || (int)s.find("that ") >= 0) {
        cout << s << endl;
        break;
      }
    }
  }
  return 0;
}