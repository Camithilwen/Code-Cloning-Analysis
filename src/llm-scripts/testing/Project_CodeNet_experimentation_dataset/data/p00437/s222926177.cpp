#include<iostream>
#include<vector>
using namespace std;

int main(){
while(1){
	int a,b,c,n,p[1002],q[1002],r[1002],s[1002],Q[302];
	for(int i=0;i<302;i++)Q[i]=2;
	scanf("%d%d%d",&a,&b,&c);
	if(a==0&&b==0&&c==0)break;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&p[i],&q[i],&r[i],&s[i]);
		if(s[i]==1){Q[p[i]]=1; Q[q[i]]=1; Q[r[i]]=1;}
	}
	for(int i=0;i<n;i++){
		if(s[i]==0){
			if(Q[p[i]]==1&&Q[q[i]]==1)Q[r[i]]=0;
			if(Q[p[i]]==1&&Q[r[i]]==1)Q[q[i]]=0;
			if(Q[r[i]]==1&&Q[q[i]]==1)Q[p[i]]=0;
		}
	}
	for(int i=1;i<=a+b+c;i++){
		printf("%d\n",Q[i]);
	}
}
}