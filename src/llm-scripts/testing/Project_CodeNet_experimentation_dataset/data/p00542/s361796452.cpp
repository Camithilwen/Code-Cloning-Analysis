#include<bits/stdc++.h>
using namespace std;

int main(){
	int s=0;
int a=0,b=INT_MAX;
int c;
for(int d=0;d<4;d++){
	scanf("%d",&c);
	a+=c;
	b=min(b,c);
}
a-=b;
b=INT_MAX;
for(int d=0;d<2;d++){
	scanf("%d",&c);
	a+=c;
	b=min(b,c);
}
printf("%d\n",a-b);
}