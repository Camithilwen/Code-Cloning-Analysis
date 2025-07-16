#include<bits/stdc++.h>
using namespace std;

int N,M;
int G[15][15];

int dp[15][(1<<15)];
int INF=2e9;

int calc(int bit,int nbit){
  int sum=0;
  for(int i=0;i<N;i++)
    if(nbit>>i&1)
      for(int j=0;j<N;j++)
        if(~bit>>j&1)
          if(~nbit>>j&1)
            sum+=G[i][j];
  return sum;
}



int rec(int pos,int bit){
  static unordered_map< int , int > mem[15];
  if( mem[pos].count(bit) )return mem[pos][bit];
  
  if(pos==N-1)return 0;
  int res=INF;

  int sup=(1<<(N-1))-1-bit;
  
  int nbit=sup;
  while(1){

    if(nbit>>pos&1){
      int cost=calc(bit,nbit);
      for(int to=0;to<N;to++){
        if(bit>>to&1)continue;
        if(nbit>>to&1)continue;
        if(G[pos][to]==0)continue;
        res=min(res, rec(to,bit|nbit) + cost - G[pos][to]);
      }
    }
    nbit--;
    nbit&=sup;
    if(nbit==0)break;
  }
  return mem[pos][bit]=res;
}

int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    G[a][b]=G[b][a]=c;
  }
  cout<< rec(0,0) <<endl;
  return 0;
}
