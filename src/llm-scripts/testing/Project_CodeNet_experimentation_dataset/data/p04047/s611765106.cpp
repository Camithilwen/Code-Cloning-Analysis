#include <iostream>
using namespace std;
int main(void){
  int n,i,j,ans=0;
  cin >>n;
  int l[200];
  int max,tmp;
  while(cin>>j){
    l[i] = j;
    i++;
  }
  cout<<endl;
  for(i=0;i<2*n-1;++i){
    max=i;
    for(j=i+1;j<2*n;++j){
      if(l[max]<l[j]){
        max=j; 
      }
    }
    tmp=l[max];
    l[max]=l[i];
    l[i]=tmp;
  }
  
  for(i=1;i<2*n;i=i+2){
    ans+=l[i];
  }
  cout<<ans;
}
