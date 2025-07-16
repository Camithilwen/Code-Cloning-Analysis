#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
vector<int> fri[501];
int ff[501];
main(){
  while(1){
    scanf("%d",&n);
    scanf("%d",&m);
    if(n==0 && m==0) break;
    memset(ff,0,sizeof(ff));
    for(int i=0;i<=501;i++)
      fri[i].clear();
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      fri[a].push_back(b);
      fri[b].push_back(a);
    }
    int M=fri[1].size();
    for(int i=0;i<M;i++){
      int N=fri[fri[1][i]].size();
      for(int j=0;j<N;j++){
	ff[fri[fri[1][i]][j]]=1;
      }
      ff[fri[1][i]]=1;
    }
    int res=0;
    for(int i=2;i<=n;i++){
      if(ff[i]==1)res++;
      //    printf("%d ",ff[i]);
    }
    printf("%d\n",res);
  }
}