#include<bits/stdc++.h>

template< typename G >
struct StronglyConnectedComponents {
    using UnWeightedGraph=std::vector<std::vector<int>>;
  const G &g;
  UnWeightedGraph gg, rg;
  std::vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(UnWeightedGraph &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};
int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<bool>> to(N,std::vector<bool>(N,false));
    std::vector<std::vector<int>> graph(N),t;
    std::vector<int> ans;
    for(int _=0;_<M;++_){
        int u,v;
        std::cin>>u>>v;
        u--;v--;
        if(ans.empty()){
            graph[u].push_back(v);
            StronglyConnectedComponents<std::vector<std::vector<int>>> scc(graph);
            scc.build(t);
            std::vector<std::vector<int>> tmp(N);
            for(int i=0;i<N;++i) tmp[scc[i]].push_back(i);
            int ok=-1;
            for(int i=0;i<N;++i) if(tmp[i].size()>1) ok=i;
            if(ok!=-1){
                int now=v;
                while(now!=u){
                    ans.push_back(now);
                    for(auto e:graph[now]) if(scc[e]==ok){
                        now=e;
                        break;
                    }
                }
                ans.push_back(u);
            }
            for(int i=0;i<N;++i) if(to[v][i]) to[u][i]=true;
        }
        else if(std::find(ans.begin(),ans.end(),u)!=ans.end()&&
                std::find(ans.begin(),ans.end(),v)!=ans.end()){
            int ch=std::find(ans.begin(),ans.end(),v)-ans.begin();
            int sz=ans.size();
            std::vector<int> tmp;
            while(ans[ch]!=u){
                tmp.push_back(ans[ch]);
                ch=(ch+1)%sz;
            }
            tmp.push_back(u);
            ans=tmp;
        }
    }
    if(ans.empty()){
        std::cout<<-1<<std::endl;
        return 0;
    }
    std::cout<<ans.size()<<std::endl;
    for(auto a:ans) std::cout<<a+1<<std::endl;
}