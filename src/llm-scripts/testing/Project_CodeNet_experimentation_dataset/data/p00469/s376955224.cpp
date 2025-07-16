#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int f(int x,int y){
	if(y<10)return x*10+y;
	return x*100+y;
}

int main(){
while(1){
	int n,k,c[100],ans=1;
	vector<int> sum;
	scanf("%d%d",&n,&k);
	if(n==0&&k==0)break;
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	int a=0;
	for(int i=0;i<n;i++){
		int a0=c[i];
		for(int j=0;j<n;j++){
			if(j!=i){
				int a1=f(a0,c[j]);
				if(k==2)sum.push_back(a1);
				else {
					for(int l=0;l<n;l++){
						if(l!=j&&l!=i){
							int a2=f(a1,c[l]);
							if(k==3)sum.push_back(a2);
							else{
								for(int m=0;m<n;m++){
									if(m!=l&&m!=j&&m!=i){
										int a3=f(a2,c[m]);
										sum.push_back(a3);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	sort(sum.begin(),sum.end());
	int s=sum.size();
	for(int i=1;i<s;i++){
		if(sum[i]!=sum[i-1])ans++;
	}
	printf("%d\n",ans);
}
}