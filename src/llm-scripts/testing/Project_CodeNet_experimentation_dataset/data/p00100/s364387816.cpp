#include<bits/stdc++.h>
using namespace std;

int main(){
  int nin;
  while(1){ 
    scanf("%d",&nin);
    if(!nin)break;

    long long int human[4002]={0};
    long long int no[4002],tanka,kazu,outflag=0;
    
    for(int i=0;i<nin;i++){
      scanf("%d %d %d",&no[i],&tanka,&kazu);
      human[no[i]]+=tanka*kazu;
    }
    
    for(int i=0;i<nin;i++){
      if(human[no[i]]>=1000000 && human[no[i]]!=-1){
	printf("%d\n",no[i]);
	human[no[i]]=-1;
	outflag=1;
      }
    }
    
    if(outflag==0)printf("NA\n");
    
  }
}