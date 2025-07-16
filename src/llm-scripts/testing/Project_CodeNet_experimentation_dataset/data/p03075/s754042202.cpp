#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int a,b,c,d,e,k;
  	cin>>a>>b>>c>>d>>e>>k;
  
  	bool dis=true;
  
  if(e-a>k){

  	dis=false;
  }

  if(dis){
  	cout<<"Yay!"<<endl;
  }
  
  else{
  	cout<<":("<<endl;
  }

}