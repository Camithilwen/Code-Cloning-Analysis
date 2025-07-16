#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>

#define rep(i,n) for(int i=0;i<int(n);i++)
#define sint(n) scanf("%d",&n);

using namespace std;


int main(){
	while(1){
		int a,b,c;
		sint(a)
		sint(b)
		sint(c)
		
		if(a==0){break;}
		int k;
		sint(k)
		
		int buhin[301]={0};
		rep(i,301){
			buhin[i]=2;
		}
		
		int e[1000],r[1000],t[1000],u[1000];
		rep(i,k){
			scanf("%d%d%d%d",&e[i],&r[i],&t[i],&u[i]);
			if(u[i]==1){
				buhin[e[i]]=buhin[r[i]]=buhin[t[i]]=1;
			}
		}
		
		
		rep(i,k){
			if(u[i]==0){
				if(buhin[e[i]]==1 && buhin[r[i]]==1){
					buhin[t[i]]=0;
				}
				if(buhin[e[i]]==1 && buhin[t[i]]==1){
					buhin[r[i]]=0;
				}
				if(buhin[t[i]]==1 && buhin[r[i]]==1){
					buhin[e[i]]=0;
				}
			}
		}
		
		rep(i,a+b+c){
			printf("%d\n",buhin[i+1]);
		}
	}
}
/*
2 2 2
4
2 4 5 0
2 3 6 0
1 4 5 0
2 3 5 1 
*/