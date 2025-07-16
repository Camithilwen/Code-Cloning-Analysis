#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define dpr(x) cerr<<#x<<": "<<x<<endl;
#define dprc(c) do{cerr<<#c<<":";for(auto&_i:(c)){cerr<<" "<<_i;}cerr<<endl;}while(0)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int INF = 1e9+7;
#define all(c) begin(c), end(c)
#define tr(i,c) for(auto i=begin(c);i!=end(c);i++)
#define rtr(i,c) for(auto i=(c).rbegin();i!=(c).rend();i++)
#define rep(i,b) for(auto i=0;i<(b);i++)
#define pb push_back
#define sz(c) int((c).size())

int cnt, m;
vi G;

void insertionSort(vi& A, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(vi& A, int n) {
  cnt = 0;
  G = vi(0);
  int g = 1;
  do {
    G.pb(g);
    g = g*3 + 1;
  } while (g <= n);
  reverse(all(G));
  m = sz(G);
  for (auto& g:G) {
    insertionSort(A, n, g);
  }
}

void dump(vi& A, const string& sep) {
  string sp = "";
  for (auto& a:A) {
    cout << sp << a;
    sp = sep;
  }
  cout << endl;
}

int main(int argc, char **argv)
{
  vi A;
  int n;
  cin >> n;
  A = vi(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  shellSort(A, n);

  cout << m << endl;
  dump(G, " ");
  cout << cnt << endl;
  dump(A, "\n");
  return 0;
}