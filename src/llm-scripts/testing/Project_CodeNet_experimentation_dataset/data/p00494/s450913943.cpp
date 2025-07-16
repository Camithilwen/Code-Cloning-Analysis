#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int main(){
	int i,j;
	int n;
	char c;
	int jc=0;
	int oc=0;
	int ic=0;
	int lev=0;
	int ans=0;
	scanf("%d",&n);
	while(scanf("%c",&c)!=EOF){
		switch(c){
		case 'J':
			if(jc==0){
				oc=0;
				ic=0;
				lev=0;
			}
			jc++;
			break;
		case 'O':
			if(oc==0){
				if(jc>0)lev=jc;
				if(ic>0)lev=0;
				jc=0;
				ic=0;
			}
			oc++;
			if(lev<oc){
				oc=0;
				lev=0;
			}
			break;
		case 'I':
			if(ic==0){
				if(lev>0)lev=oc;
				jc=0;
				oc=0;
			}
			ic++;
			if(ic>=lev)ans=max(ans,lev);
			break;
		}
	}
	printf("%d\n",ans);
}
			