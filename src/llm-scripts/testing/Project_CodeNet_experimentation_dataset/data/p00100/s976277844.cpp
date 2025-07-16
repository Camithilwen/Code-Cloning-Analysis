#include<iostream>
using namespace std;
int main(){
  long long data[2][4000],n,i,f,id,a,b;
  while(1){
    cin>>n;
    if(n==0) break;
    for(i=0; i<4000; i++) data[0][i]=-1,data[1][i]=0;
    for(i=0;i<n;i++){
      cin>>id>>a>>b;
      for(f=0;f<i+1;f++){
	if(data[0][f]==id){
	  (a*b<1000000)? (data[1][f]+=(a*b)) : (data[1][f]=1000000);
	  break;
	}else if(data[0][f]==-1){
	  data[0][f]=id;
	  (a*b<1000000)? (data[1][f]=(a*b)) : (data[1][f]=1000000);
	  break;
	}
      }
    }
    for(i=0,f=0;i<n;i++){
      if(data[1][i]>=1000000)cout<<data[0][i]<<"\n",f=1;
      if(data[0][i]==-1)break;
      //cout<<"id : "<<data[0][i]<<" sale: "<<data[1][i]<<endl;
    }
    if(f==0)cout<<"NA"<<endl;
  }
}