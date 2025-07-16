#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  long long n,q;
  cin >> n >> q;
  long long s[n],t[n],x[n],d[q];
  pair<long long, int> p[n];
  for(int i=0;i<n;i++){
    cin >> s[i] >> t[i] >> x[i];
    p[i]=make_pair(x[i], i);
  }
  sort(p, p+n);
  vector<pair<long long, int> > vec;
  bool active[n];
  for(int i=0;i<n;i++){
    vec.push_back(make_pair(s[p[i].second]-x[p[i].second]-1, i));
    vec.push_back(make_pair(t[p[i].second]-x[p[i].second]-1, i));
    active[i]=false;
  }
  for(int i=0;i<q;i++){
    cin >> d[i];
    vec.push_back(make_pair(d[i], -1));
  }
  sort(vec.begin(), vec.end());
  priority_queue<int, vector<int>, greater<int> > que;
  for(size_t i=0;i<vec.size();i++){
    if(vec[i].second == -1){
      if(!que.empty()){
        cout << p[que.top()].first << endl;
      }else{
        cout << -1 << endl;
      }
    }else{
      long long idx = vec[i].second;
      if(active[idx]){ //工事終了
        active[idx] = false;
        if(idx == que.top()){
          que.pop();
          while(!que.empty()){
            if(active[que.top()]){
              break;
            }else{
              que.pop();
            }
          }
        }
      }else{ //工事開始
        active[idx] = true;
        que.push(idx);
      }
    }
  }
  return 0;
}
