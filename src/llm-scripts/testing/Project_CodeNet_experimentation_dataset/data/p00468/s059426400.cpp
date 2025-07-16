#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  while(1){
  int n,i,a[10000],b[10000],c=0,m,j,d[1000000]={0},y=1,e=1,g=0,w=0;
    cin >> n >> m;
    if(n==0 && m==0){
      break;
    }
    for(i=1;i<=m;i++){
      cin >> a[i] >> b[i];
    }
    for(i=1;i<=m;i++){
      if(a[i]==1){
	d[y]=b[i];
	y++;
      }
      else if(b[i]==1){
	d[y]=a[i];
	y++;
      }
    }
    w=y;
    for(i=1;i<w;i++){
      for(j=1;j<=m;j++){
	if(d[i]==a[j] && b[j]!=1){
	  d[y]=b[j];
	  y++;
	}
	if(d[i]==b[j] && a[j]!=1){
	  d[y]=a[j];
	  y++;
	}
      }
    }
    sort(d,d+y);
    for(i=1;i<y;i++){
      if(c!=d[i]){
	g++;
      }
      c=d[i];
    }

    cout << g << endl;
  }
}