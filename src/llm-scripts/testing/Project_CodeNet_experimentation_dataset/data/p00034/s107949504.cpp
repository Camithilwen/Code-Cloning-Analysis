#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int a[10];
	int v1,v2;
	while(scanf("%d",a)!=EOF){
		for(int i=1;i<10;i++){
			scanf(",%d",&a[i]);
			a[i] += a[i-1];
		}
		scanf(",%d,%d\n",&v1,&v2);
		int ans;
		for(int i=9;i>=0;i--){
			if(v1*a[9] <= a[i]*(v1+v2))ans=i;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}