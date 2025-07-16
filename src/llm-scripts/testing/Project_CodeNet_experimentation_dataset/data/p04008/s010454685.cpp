#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;
int a[100000];
vector <int> children[100000];
int d[100000];
bool done[100000];
void set_d(int cur, int cur_d){
  d[cur] = cur_d;
  for(int i = 0; i < children[cur].size(); i++){
    set_d(children[cur][i], cur_d + 1);
  }
}

void set_done(int cur){
  if(done[cur]){
    return;
  }
  done[cur] = true;
  for(int i = 0; i < children[cur].size(); i++){
    set_done(children[cur][i]);
  }
}

int main(){
  int N;
  long long K;
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> a[i];
    a[i] --;
    if(i != 0){
      children[a[i]].push_back(i);
    }
  }

  for(int i = 0; i < N; i++){
    d[i] = INT_MAX;
  }

  set_d(0, 0);
  int ans;
  if(a[0] == 0){
    ans = 0;
  } else {
    ans = 1;
  }

  vector <pair <int, int> > tmp;
  for(int i = 0; i < N; i++){
    if(d[i] <= K){
      //done[i] = true;
    } else {
      tmp.push_back(make_pair(d[i], i));
    }
  }
  sort(tmp.begin(), tmp.end());
  reverse(tmp.begin(), tmp.end());

  for(int i = 0; i < tmp.size(); i++){
    int cur_d = tmp[i].first;
    int cur = tmp[i].second;
    if(!done[cur]){
      int teleport = cur;
      for(int i = 0; i < K - 1; i++){
        teleport = a[teleport];
      }
      ans ++;
      set_done(teleport);
    }

  }

  cout << ans << endl;
  return 0;
}
