#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
vector<int> part_ans(0);
vector<int> t_ans;
bool fin=false;
int last=-1;

vector<int> topo_sort1(vector<vector<int>> e)
{
  int n=e.size();
  vector<int> ans(0);
  vector<int> ins(n,0);
  int i,j;
  rep(i,n)
  {
    rep(j,e[i].size())
    {
      ins[e[i][j]]++;
    }
  }
  queue<int> s;
  rep(i,n) if(ins[i]==0)s.push(i);
  while(!s.empty())
  {
    int now=s.front();
    s.pop();
    ans.emplace_back(now);
    rep(i,e[now].size())
    {
      ins[e[now][i]]--;
      if(ins[e[now][i]]==0)
      {
        s.push(e[now][i]);
      }
    }
  }
  return ans;
}

void dfs(int now,vector<bool> &visited,vector<vector<int>> e,int count)
{
  if(fin)return;
  int i,j;
  visited[now]=true;
  part_ans.emplace_back(now);
  int pas=part_ans.size();
  rep(i,e[now].size())
  {
    if(!visited[e[now][i]])
    {
      dfs(e[now][i],visited,e,count+1);
      if(fin)
      {
        return;
      }
    }
    else
    {
      last=e[now][i];
      bool ap=false;
      rep(j,part_ans.size())
      {
        if(!ap)
        {
          if(part_ans[j]==last)
          {
            ap=true;
            t_ans.emplace_back(part_ans[j]);
          }
        }
        else
        {
          t_ans.emplace_back(part_ans[j]);
        }
      }
      fin=true;
      break;
    }
  }
  visited[now]=false;
  part_ans.erase(part_ans.end()-1,part_ans.end());
}

int main()
{
  int n,m;cin>>n>>m;
  vector<int> a(m);
  vector<int> b(m);
  int i,j;
  rep(i,m)cin>>a[i]>>b[i];
  rep(i,m)
  {
    a[i]--;
    b[i]--;
  }
  vector<vector<int>> e(n);
  rep(i,m)
  {
    e[a[i]].emplace_back(b[i]);
  }
  vector<int> ans=topo_sort1(e);
  if(ans.size()==n)
  {
    cout<<-1<<endl;
  }
  else
  {
    rep(i,n)
    {
      vector<bool> visited(n,false);
      dfs(i,visited,e,0);
      if(fin)break;
    }
    while(true)
    {
      vector<bool> inside(n,false);
      rep(i,t_ans.size())
      {
        inside[t_ans[i]]=true;
      }
      vector<int> ins(n,0);
      vector<int> outs(n,0);
      bool ok=true;
      vector<vector<int>> mine(n);
      rep(i,m)
      {
        if(inside[a[i]]&&inside[b[i]])
        {
          ins[b[i]]++;
          outs[a[i]]++;
          mine[a[i]].emplace_back(b[i]);
        }
      }
      int insum=0;
      int outsum=0;
      rep(i,n)
      {
        if(inside[i])
        {
          if(ins[i]!=1||outs[i]!=1)
          {
            ok=false;
          }
        }
      }
      if(ok)break;
      int stat=-1;
      rep(i,t_ans.size())
      {
        if(outs[t_ans[i]]>1)
        {
          stat=i;
          break;
        }
      }
      vector<bool> use(n,true);
      rep(i,outs[t_ans[stat]])
      {        
        vector<bool> vis(n,false);
        int now=t_ans[stat];
        vis[now]=true;
        now=mine[now][i];
        while(true)
        {
          vis[now]=true;
          now=mine[now][0];
          if(vis[now])break;
        }
        rep(j,n)
        {
          if(!vis[j])use[j]=false;
        }
      }
      t_ans.erase(all(t_ans));
      rep(i,n)if(use[i])t_ans.emplace_back(i);
    }
    cout<<t_ans.size()<<endl;
    rep(i,t_ans.size())
    {
      cout<<t_ans[i]+1<<endl;
    }
  }
}