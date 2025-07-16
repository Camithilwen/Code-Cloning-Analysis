#include <bits/stdc++.h>
using namespace std;
using Graph= vector<vector<int>>;
const int TBC= -1;

void DFS(const Graph &tree, int parent, int root, vector<int> *parents, vector<int> *pre_timestamp, vector<int> *post_timestamp, vector<int> *depth){
  if(parents->at(root)==TBC){
    parents->at(root)= parent;
    pre_timestamp->at(root)= depth->size();
  }
  int depth_root= (!depth->empty()) ? depth->back()+ 1
                                    : 0;
  depth->emplace_back(depth_root);
  for(auto child:tree.at(root)){
    if(child != parent){
      DFS(tree, root, child, parents, pre_timestamp, post_timestamp, depth);
      depth->emplace_back(depth_root);
    }
  }
  post_timestamp->at(root)= depth->size();
}

int main(){
  int N,v0_runner,v0_trailer;
  cin >> N >> v0_runner >> v0_trailer;
  const int M= N-1;
  v0_runner--; v0_trailer--; // 1-indexed -> 0-indexed

  Graph tree(N);

  int v1,v2;
  for(int i=0; i<M; i++){
    cin >> v1 >> v2;
    v1--; v2--; // 1-indexed -> 0-indexed
    tree.at(v1).emplace_back(v2);
    tree.at(v2).emplace_back(v1);
  }

  vector<int> parents(N, TBC);
  vector<int> pre_timestamp(N, TBC);
  vector<int> post_timestamp(N, TBC);
  vector<int> depth;

  DFS(tree, -1, v0_trailer, &parents, &pre_timestamp, &post_timestamp, &depth);

  int depth0_runner= depth.at(pre_timestamp.at(v0_runner));
  int cnt_up= (depth0_runner- 1)/ 2;
  int pos_runner= v0_runner;
  for(int i=0; i<cnt_up; i++){
    pos_runner= parents.at(pos_runner);
  }

  int depth1_runner= depth.at(pre_timestamp.at(pos_runner));
  int left = pre_timestamp.at(pos_runner);
  int right= post_timestamp.at(pos_runner);
  int depth_tree= *max_element(depth.begin()+ left, depth.begin()+ right);

  int ans= (depth0_runner/ 2)+ (depth_tree- depth1_runner);

  cout << ans << endl;
}