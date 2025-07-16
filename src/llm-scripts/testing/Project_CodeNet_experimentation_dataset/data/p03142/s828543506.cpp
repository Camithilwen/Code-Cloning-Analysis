#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

int MX = 100005;
vector<int> parents(MX);
vector<int> in(MX);
vector<vector<int>> tree(MX,vector<int>());
  
int main() {
  int n,m;
  cin >> n >> m;
  rep(i,n-1+m){
    int a,b;
    cin >> a >> b;
    --a; --b;
    tree.at(a).push_back(b);
    in.at(b) ++;
  }
  int parent = 0;
  rep(i,n){
    if(in.at(i) == 0){
      parent = i;
      break;
    }
  }
  parents.at(parent) = -1;
  queue<int> q;
  q.push(parent);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(auto i:tree.at(now)){
      in.at(i) --;
      if(in.at(i) == 0){
        parents.at(i) = now;
        q.push(i);
      }
    }
  }

  rep(i,n) cout << parents.at(i)+1 << endl;

  return 0;
}

