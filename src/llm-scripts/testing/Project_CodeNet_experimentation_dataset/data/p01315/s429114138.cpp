#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  /*
  cout<< ("onion">"potato") <<endl;

  return 0;
  */
  int h,i,j;
  int y[50],z[50],n,p,a,b,c,d,e,f,s,m;
  string l[50];
  while(cin>>n&&n){
    for(i=0;i<n;i++){
      cin>>l[i]>>p>>a>>b>>c>>d>>e>>f>>s>>m;
      y[i]=f*s*m-p;
      z[i]=a+b+c+(d+e)*m;
    }
    h=1;
    for(i=0;h;i++){
      h=0;
      for(j=1;j<n-i;j++){
	if(y[j-1]*z[j]<y[j]*z[j-1]){
	  swap(y[j-1],y[j]);
	  swap(z[j-1],z[j]);
	  swap(l[j-1],l[j]);
	  h=1;
	}else if(y[j-1]*z[j]==y[j]*z[j-1]){
	  if(l[j-1]>l[j]){
	    swap(y[j-1],y[j]);
	    swap(z[j-1],z[j]);
	    swap(l[j-1],l[j]);
	    h=1;
	  }
	}
      }
    }
    for(i=0;i<n;i++)
      cout<<l[i]<<endl;
    cout<<"#"<<endl;
  }
  return 0;
}