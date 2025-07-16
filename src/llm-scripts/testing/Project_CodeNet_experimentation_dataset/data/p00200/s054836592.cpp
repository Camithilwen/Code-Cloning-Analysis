#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=1;i<=n;i++)
using namespace std;
typedef pair<int, int> P;

int c[100][100]={};
int t[100][100]={};

int main()
{
  int n,m,a,b;
  int i,j,k;
  int p,q,r;

  while(1){
    cin>>n>>m;
    if(n==0 && m==0)break;

    rep(i,m)rep(j,m)c[i][j]=t[i][j]=INF;//INFテ」ツ?ァテ・ツ按敕ヲツ慊淌・ツ個?
    rep(i,m)c[i][i]=t[i][i]=0;//テ・ツ青古ゥツァツ?」ツ?ッ0

    rep(i,n){
      cin>>a>>b;
      cin>>c[a][b]>>t[a][b];
      c[b][a]=c[a][b];
      t[b][a]=t[a][b];
    }
    
    rep(k,m)rep(i,m)rep(j,m){
      c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
      t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
    }

    cin>>k;
    rep(i,k){
      cin>>p>>q>>r;
      if(r)
	cout<<t[p][q]<<endl;
      else
	cout<<c[p][q]<<endl;
    }
  }
}