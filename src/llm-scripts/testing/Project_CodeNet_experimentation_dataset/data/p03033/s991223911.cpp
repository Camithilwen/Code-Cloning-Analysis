#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> vec(N,vector<int>(3));
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      cin >> vec.at(i).at(j);
    }
  }
  vector<int> query(Q+2,-1e9);
  for(int i=1; i<=Q; i++){
    cin >> query.at(i);
  }
  query.at(Q+1) = 1e9+10;
  vector<vector<int>> in(Q+2,vector<int>(0));
  vector<vector<int>> out(Q+2,vector<int>(0)); 
  
  vector<int>::iterator pos;
  int idx;
  for(int i=0; i<N; i++){
    int s = vec.at(i).at(0);
    int e = vec.at(i).at(1);
    int p = vec.at(i).at(2);
    pos = lower_bound(query.begin(),query.end(),s-p);
    idx = distance(query.begin(),pos);
    in.at(idx).push_back(p);
    pos = lower_bound(query.begin(),query.end(),e-p);
    idx = distance(query.begin(),pos);
    out.at(idx).push_back(p);
  }
  
  map<int,int> mp;
  mp[1e9+10] = 1;
  for(int i=0; i<Q+1; i++){
    for(int j=0; j<in.at(i).size(); j++){
      if(mp.count(in.at(i).at(j))){
        mp[in.at(i).at(j)]++;
      }
      else{
        mp[in.at(i).at(j)] = 1;
      }
    }
    for(int j=0; j<out.at(i).size(); j++){
      mp[out.at(i).at(j)]--;
      if(mp[out.at(i).at(j)] == 0){
        mp.erase(out.at(i).at(j));
      }
    }
    if(i != 0){
      int x = mp.begin()->first;
      if(x == 1e9+10){
        cout << -1 << endl;
      }
      else{
        cout << x << endl;
      }
    }
  }
}