#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
char s[4002];
int r[4002],g[4002],b[4002];
long long int ans = 0;
int main(){
	scanf("%d",&N);
	scanf("%s",&s[1]);
	//printf("%d\n",N);
	//printf("%s\n",&s[1]);

	for(int i=N-1;i>0;i--){
		r[i] = r[i+1];
		g[i] = g[i+1];
		b[i] = b[i+1];

		if(s[i+1] == 'R')r[i] ++;
		else if (s[i+1] == 'G') g[i]++;
		else b[i]++;
	}
	//for(int i=1;i<=N;i++)printf("%d ",r[i]);
//		printf("\n");
	//for(int i=1;i<=N;i++)printf("%d ",g[i]);
//		printf("\n");
//	for(int i=1;i<=N;i++)printf("%d ",b[i]);
//		printf("\n");

	for(int i=1;i<=N-2;i++){
		for(int j=i+1;j<=N-1 ; j++){
			if(s[i] == s[j])continue;
			int x= j-i;
			
			

			if( (s[i] == 'R' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'R')){
				ans+=b[j]; 
				if(x+j <=N && s[x+j] == 'B') ans--;
			}
			else if ((s[i] == 'R' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'R')){
				ans+=g[j]; 
				if(x+j <=N && s[x+j] == 'G') ans--;
			}
			else {
				ans+=r[j]; 
				if(x+j<=N && s[x+j] == 'R') ans--;
			}
		//	printf("%d %d %d\n",i,j,ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}