#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  deque<int> d;
  int ans = 0;
  for(int i = 0;i < n;i++){
    int temp = a[i];
    int p = lower_bound(d.begin(),d.end(),temp) - d.begin();
    if(p == 0) d.push_front(temp);
    else d[p-1] = temp;
  }
  cout << d.size() << endl;
}