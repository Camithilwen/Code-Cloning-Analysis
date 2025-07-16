#include<iostream>
using namespace std;
int main(){
  while(1){
    int n,m,b,c,cnt=0,a[101]={};
    cin>>n>>m;
    if(n+m==0)break;
    for(int i=0;i<n;i++){
      cin>>b;
      for(int j=0;j<b;j++){
	cin>>c;
	a[c]++;
      }
    }
    int x=0,max=0;
    for(int i=0;i<101;i++){
      if(max<a[i]&&m<=a[i]){
	max=a[i];
	x=i;
      }
    }
    cout<<x<<endl;
  }
  return 0; 
}