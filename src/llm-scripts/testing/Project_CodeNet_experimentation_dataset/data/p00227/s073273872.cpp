#include<iostream>
#include<algorithm>
#include<functional>
#define MAX 1000

int main(){
	int n,m,p[MAX];
	while(1){
		int f=0,m1=0;
		std::cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;++i){
			std::cin>>p[i];
		    m1+=p[i];
		}
		std::sort(p,p+n,std::greater<int>());
		int c=n%m;
		for(int i=0;i<n-c;++i){
			if((i+1)%m==0)
				f+=p[i];
		}
		std::cout<<m1-f<<std::endl;
	}
	return 0;
}