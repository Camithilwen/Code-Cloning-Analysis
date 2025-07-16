#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int N,X,a=0;
  cin>>N>>X;
  int l[N];
  for(int i=0;i<N;++i)cin>>l[i];
  
  sort(l,l+N);
  	for(int i=0;i<N;++i){
      X-=l[i];
      	if(X>=0)a++;
      	else break;
    }
  if(X>0)cout<<a-1;
  else cout<<a;
  
  
  
  
}
