#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
// typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 998244353;
const lli e3 = 1 << 12;

lli n,m,q;
lli s[e3][e3];
lli query[e5][4];
lli v_edge[e3][e3];
lli h_edge[e3][e3];

int main(){
  cin >> n >> m >> q;
  for(lli i = 1;i <= n;i++){
    string hoge;
    cin >> hoge;
    for(lli j = 0;j < m;j++){
      s[i][j+1] = hoge[j]-'0';
    }
  }
  for(lli i = 0;i < q;i++){
    for(lli j = 0;j < 4;j++) cin >> query[i][j];
  }
  for(lli i = 1;i < n;i++){
    for(lli j = 1;j <= m;j++){
      v_edge[i][j] = (s[i][j] == 1 && s[i+1][j] == 1);
    }
  }
  for(lli i = 1;i <= n;i++){
    for(lli j = 1;j < m;j++){
      h_edge[i][j] = (s[i][j] && s[i][j+1] == 1);
    }
  }
  // s
  for(lli i = 1;i <= n;i++){
    for(lli j = 1;j <= m;j++){
      s[i][j] += s[i-1][j];
    }
  }
  for(lli i = 1;i <= n;i++){
    for(lli j = 1;j <= m;j++){
      s[i][j] += s[i][j-1];
    }
  }
  // v_edge
  for(lli i = 1;i < n;i++){
    for(lli j = 1;j <= m;j++){
      v_edge[i][j] += v_edge[i-1][j];
    }
  }
  for(lli i = 1;i < n;i++){
    for(lli j = 1;j <= m;j++){
      v_edge[i][j] += v_edge[i][j-1];
    }
  }
  // h_edge
  for(lli i = 1;i <= n;i++){
    for(lli j = 1;j < m;j++){
      h_edge[i][j] += h_edge[i-1][j];
    }
  }
  for(lli i = 1;i <= n;i++){
    for(lli j = 1;j < m;j++){
      h_edge[i][j] += h_edge[i][j-1];
    }
  }
  for(lli i = 0;i < q;i++){
    lli vertices = s[query[i][2]][query[i][3]]
    -s[query[i][2]][query[i][1]-1]
    -s[query[i][0]-1][query[i][3]]
    +s[query[i][0]-1][query[i][1]-1];
    lli v = v_edge[query[i][2]-1][query[i][3]]
    -v_edge[query[i][2]-1][query[i][1]-1]
    -v_edge[query[i][0]-1][query[i][3]]
    +v_edge[query[i][0]-1][query[i][1]-1];
    lli h = h_edge[query[i][2]][query[i][3]-1]
    -h_edge[query[i][2]][query[i][1]-1]
    -h_edge[query[i][0]-1][query[i][3]-1]
    +h_edge[query[i][0]-1][query[i][1]-1];
    // cerr << vertices << " " << v << " " << h << endl;
    cout << vertices-v-h << endl;
  }

}
