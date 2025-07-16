#include <cstdio>
using namespace std;
int n,d1,d2,s;
int f[620][620];
void work(int d){
	int p=0;
	while(d%4==0){
		d/=4;
		p++;
	}
	if(d&1){
		for(int i=0;i<2*n;i++)
			for (int j=0;j<2*n;j++)
				if(((i>>p)+(j>>p))&1)
					f[i][j]=1;
	}else{
		for(int i=0;i<2*n;i++)
			for(int j=0;j<2*n;j++)
				if((i>>p)&1)
					f[i][j]=1;
	}
}
int main(){
	scanf("%d%d%d",&n,&d1,&d2);
	work(d1);
	work(d2);
	for(int i=0;i<2*n;i++){
		for(int j=0;j<2*n;j++){
			if(s<n*n && !f[i][j]){
				printf("%d %d\n",i,j);
				s++;
			}
		}
	}
	return 0;
}