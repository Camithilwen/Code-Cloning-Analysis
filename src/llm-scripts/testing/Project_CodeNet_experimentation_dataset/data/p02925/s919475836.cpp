#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
struct Node{
  int row_no,col_no;
  int indegree;
  int dist;
  vector<Node*> child;
  vector<Node*> par;
  void build(int i,int j){
      row_no=i;col_no=j;indegree=0;
      dist=-1;
  }
};
vector<pair<int,int>> toposo(vector<vector<Node>> const& node,int n){
    vector<P> res;
    queue<Node> que;
    rep1(i,n){
        rep1(j,n){
            if(node[i][j].indegree==0){
                que.push(node[i][j]);
            }
        }
    }
    while(!que.empty()){
        Node buf=que.front();que.pop();
        int num=buf.child.size();
        res.push_back({buf.col_no,buf.row_no});
        rep(i,num){
            buf.child[i]->indegree-=1;
            if(buf.child[i]->indegree==0){
                que.push(*buf.child[i]);
            }
        }
    }
    return res;
}
void dfs(Node& node){
    if(node.dist!=-1){
        return;
    }
    int num=node.par.size();
    int res=0;
    rep(i,num){
        dfs(*node.par[i]);
        res=max(res,node.par[i]->dist+1);
    }
    node.dist=res;
}
signed main(){
    int n;cin>>n;
    vector<vector<Node>> node(n+1,vector<Node>(n+1));
    rep1(i,n){
        rep1(j,n)node[i][j].build(i,j);
    }
    rep1(i,n){
        int last=0;
        rep(j,n-1){
            int a;cin>>a;
            if(last==0){
                last=a;
                continue;
            }
            int mx=max(i,a);
            int mn=min(i,a);
            node[mx][mn].par.push_back(&node[max(last,i)][min(last,i)]);
            node[mx][mn].indegree+=1;
            node[max(last,i)][min(last,i)].child.push_back(&node[mx][mn]);
            last=a;
        }
    }
    if(toposo(node,n).size()<n*n){
        cout<<-1<<"\n";
        return 0;
    }
    int res=0;
    rep1(i,n){
        rep1(j,n){
            if(j>=i)break;
            if(node[i][j].child.size()==0){
                dfs(node[i][j]);
                res=max(res,node[i][j].dist);
                //printf("i,j=%lld,%lld, res=%lld\n",i,j,res);
            }
        }
    }
    cout<<res+1<<"\n";
    return 0;
}
