#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;

  // person q is stopped by construction i
  // S_i <= D_q + X_i < T_i
  // S_i - X_i <= D_q < T_i - X_i
  // for i of smallest X_i

  vector<pair<int, pair<int, int>>> X_interval(N);
  for(int i = 0; i < N; i++){
    int s, t, x;
    cin >> s >> t >> x;
    X_interval[i] = make_pair(x, make_pair(s - x, t - x));
  }

  vector<int> D(Q);
  for(auto& x: D){
    cin >> x;
  }
  
  vector<pair<int, pair<int, bool>>> time_x_add;
  for(int i = 0; i < N; i++){
    int x = X_interval[i].first;
    int begin_time = X_interval[i].second.first, end_time = X_interval[i].second.second;
    time_x_add.push_back(make_pair(begin_time, make_pair(x, true)));
    time_x_add.push_back(make_pair(end_time, make_pair(x, false)));
  }
  sort(time_x_add.begin(), time_x_add.end());
  
  int next_event_idx = 0;
  set<int> X;
  for(int q = 0; q < Q; q++){
    while(next_event_idx < 2 * N && time_x_add[next_event_idx].first <= D[q]){
      int x = time_x_add[next_event_idx].second.first;
      bool add = time_x_add[next_event_idx].second.second;
      if(add){
        X.insert(x);
      }else{
        X.erase(x);
      }
      next_event_idx++;
    }
    if(X.size() > 0){
      cout << *X.begin() << endl;
    }else{
      cout << -1 << endl;
    }
  }

}

