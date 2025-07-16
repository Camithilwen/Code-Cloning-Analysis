#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
const long long INF = 1LL << 60;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
vector<char> Alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main()
{
  cout << fixed << setprecision(10);
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  bool ok = false;
  int M = 0;
  int g = 0;
  rep(i,N) 
  {
    cin >> A[i];
    if(A[i]==K)
    {
      ok = true;
    }
    M = max(M,A[i]);
    if(i==0) g = A[0];
    g = gcd(A[i],g);
  }
  if(g==1)
  {
    ok = true;
  }
  else
  {
    if(gcd(g,K)!=g)
    {
      ok = false;
    }
    else
    {
      ok = true;
    }
  }
  if(M<K)
  {
    ok = false;
  }
  if(ok)
  {
    cout << "POSSIBLE" << endl;
  }
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
