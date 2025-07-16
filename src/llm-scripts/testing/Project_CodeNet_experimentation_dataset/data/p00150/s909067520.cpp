#include<iostream>
using namespace std;
int main(){
  int n,m,most1,most2,d[11000]={0};
  while(1){
    cin >> n;
    if(n==0){
      break;
    }

    most1=0;most2=0;
    for(int i=0;i<10100;i++){
      d[i]=0;
    }

    for(int i=2;i*i<=n;i++){
      if(d[i]==0){
	for(int j=i+i;j<=n;j+=i){
	  d[j]=1;
	}
      }
    }
    
    for(int i=n;i>=0;i--){
      if(d[i]==0 && d[i-2]==0){
	most1=i-2;
	most2=i;
	break;
      }
    }

    cout << most1 << " " << most2 << endl;
  }
}