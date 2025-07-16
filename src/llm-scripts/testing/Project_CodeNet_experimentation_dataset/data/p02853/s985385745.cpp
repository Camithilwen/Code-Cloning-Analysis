#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int A,B;
const int c[5]={0,300000,200000,100000,0};
int main(){
	A=read(),B=read();
	if(A==1&&B==1){
		return !printf("1000000\n");
	}
	A=min(A,4),B=min(B,4);
	printf("%d\n",c[A]+c[B]);
	return 0;
}

