#include<stdio.h>
#include<algorithm>
using namespace std;
char str[110];
int b[110];
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<a;i++)scanf("%d",b+i);
		scanf("%s",str);
		for(int i=0;str[i];i++){
			int p=0;
			if('a'<=str[i]&&str[i]<='z')p=str[i]-'a';
			else p=str[i]-'A'+26;
			p-=b[i%a];
			if(p<0)p+=52;
			if(p<26)str[i]='a'+p;
			else str[i]='A'+p-26;
		}
		printf("%s\n",str);
	}
}