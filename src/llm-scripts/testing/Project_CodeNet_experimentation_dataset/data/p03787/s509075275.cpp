#include <bits/stdc++.h>
using namespace std;
#define int long long

struct UnionFind{
  int num;//連結成分の数
  vector<int> r,p;//そのグループのサイズ,自分の親っぽいやつ
  UnionFind(){}
  UnionFind(int n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}

  int find(int x){//どのグループに所属するか
    return (x==p[x]?x:p[x]=find(p[x]));//xがグループの名前と一致するまでxを親にする
  }

  bool same(int x,int y){//同じグループかどうか
    return find(x)==find(y);
  }

  void unite(int x,int y){//xとyを同じグループにする
    x=find(x);y=find(y);//xとyのグループの名前をどっちかが変える
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);//サイズが大きい方をxとする
    r[x]+=r[y];//yの親をxにする（今までyだったグループ名がxになる）
    p[y]=x;
    num--;
  }

  int size(int x){//グループの大きさ
    return r[find(x)];
  }

  int count() const{//グループの数
    return num;
  }
};

signed main(){
  int n,m;cin>>n>>m;
  vector<int> edge[n];
  UnionFind uf(n);
  while(m--){
    int u,v;cin>>u>>v;u--;v--;
    uf.unite(u,v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<int> arr(n,-1);
  vector<int> ni,no,si;
  for(int i=0;i<n;i++){
    if(uf.size(i)==1){
      si.push_back(i);
      continue;
    }
    if(~arr[i])continue;
    arr[i]=0;
    bool out=false;
    queue<int> que;
    que.push(i);
    while(que.size()){
      int p=que.front();que.pop();
      for(int q:edge[p]){
        if(~arr[q]){
          if(arr[q]==arr[p])out=1;
        }
        else{
          arr[q]=arr[p]^1;
          que.push(q);
        }
      }
    }
    if(out)no.push_back(uf.size(i));
    else ni.push_back(uf.size(i));
  }
  int ans=0;
  int a=ni.size(),c=no.size(),e=si.size();
  ans=2*a*a+2*a*c+c*c+2*e*n-e*e;
  cout<<ans<<endl;
}

/*
解説AC
連結成分なのでどう言う時に繋がっていくかを考える必要があって、それを元のグラフでの連結成分と結びつける問題
実験コードでひらめく感じはしなくて、でも手を動かすのも相当大変
解説記事も全然なくて考察フローがしっかり考えることしかなさそう？えーちょっとまだ分からんな
自分で解説記事書くしかないかなぁ
FA13分ってなんだよ
*/
