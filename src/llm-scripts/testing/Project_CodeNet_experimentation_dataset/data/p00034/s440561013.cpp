#include<iostream>
#include<numeric>
#include<cstdio>

int l[10],v,v2;

int main(){
	while(true){
		for(int i=0;i<10;i++){
			if(scanf("%d,",&l[i])==EOF)return 0;
		}
		if(scanf("%d,%d",&v,&v2)==EOF)return 0;

		double k=(double)std::accumulate(l,l+10,0)/(v+v2)*v;

		int sum=0;
		for(int i=0;i<10;i++){
			sum+=l[i];
			if(sum>=k){
				std::cout<<i+1<<std::endl;
				break;
			}
		}
	}

	return 0;
}