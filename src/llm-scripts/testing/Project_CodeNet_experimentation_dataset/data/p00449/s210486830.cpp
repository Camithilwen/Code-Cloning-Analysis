#include<algorithm>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i,j;
  int a[100][100],b[100],c[100],m,n;
  int mn;
  while(cin>>n>>m&&n+m){
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	a[i][j]=200000000;
    for(i=0;i<m;i++){
      int p,q,r;
      cin>>p;
      if(p){
	cin>>p>>q>>r;
	p--;
	q--;
	a[p][q]=a[q][p]=min(a[p][q],r);
      }else{
	cin>>p>>q;
	p--;
	q--;
	memset(b,-1,sizeof(b));
	b[p]=1;
	c[p]=0;
	for(j=0;j<n;j++){
	  if(j!=p)
	    c[j]=c[p]+a[p][j];
	}
	for(;;){
	  mn=q;
	  for(j=0;j<n;j++){
	    if(b[j]==-1&&c[mn]>c[j])
	      mn=j;
	  }
	  if(mn==q)
	    break;
	  b[mn]=1;
	  for(j=0;j<n;j++)
	    c[j]=min(c[j],c[mn]+a[mn][j]);
	}
	if(c[q]==200000000)
	  cout<<-1<<endl;
	else
	  cout<<c[q]<<endl;
      }
    }
  }
  return 0;
}