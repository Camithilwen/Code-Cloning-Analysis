#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	char s[10];
	int i,a,x=0,y=0,z=0,b=0,c=0,d=1000;
	scanf("%s",s);
	a=strlen(s);
	for(i=0;i<a-2;i++){
		x=s[i]-'0';
		y=s[i+1]-'0';
		z=s[i+2]-'0';
		b=(x*100)+(y*10)+z;
		c=753-b;
		if(c<0) c*=-1;
		if(d>c) d=c;
	}
	printf("%d\n",d);
	return 0;
}
