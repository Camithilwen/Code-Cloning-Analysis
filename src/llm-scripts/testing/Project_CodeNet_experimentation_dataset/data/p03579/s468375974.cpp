#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl #define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl #define no cout<<"no"<<endl
#define vec(a,y,x)  vector<vector<char>> a (y,vector<char>(x))
const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};

in sum_vec(vector<int> a){
  in sum=0;
  rep(i,a.size())
    sum+=a.at(i);
  return sum;
}

vector<int> color;
bool dfs (vector<vector<int>>&G,int v,int cur){
  color.at(v)=cur;
  for(int next_v : G.at(v)){
    //cout<<"v:"<<v<<" next_v:"<<next_v<<" ";
    if(color.at(next_v)==-1){
      //cout<<"未探索"<<endl;
      if(!dfs(G,next_v,1-cur)) return false;
    }
    else{
      if(color.at(next_v)==cur) {/*cout<<"矛盾"<<endl;*/ return false;}
      if(color.at(next_v)==1-cur){/*cout<<"矛盾無し"<<endl;*/ continue;}
    }
  }
  return true;
}

int main(){
  in m;
  in n;
  cin>>n>>m;
  vector<vector<int>> G(n);
  
  rep(i,m){
    int a,b;
    cin>>a>>b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);
  }
  color.assign(n,-1);
  in sum;
    
  if(dfs(G,0,0)){
    sum=sum_vec(color);
    printf("%ld \n",sum*(n-sum)-m);
  }
  else
    printf("%ld \n",(n*(n-1))/2-m);
  //color.assign(n,-1);
  //cout<<dfs(G,0,0)<<endl;
  //cout<<sum<<endl;
  //rep(i,n)
    //cout<<color.at(i);
  
}