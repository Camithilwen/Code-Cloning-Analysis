#include<cstdio>
#include<cmath>
#include <stdlib.h>
#include<algorithm>

using namespace std;

int main(){
	int ans;
	char sen[100];
	while( scanf("%s",&sen) != EOF ){
		ans=0;
		for(int i=0;sen[i]!='\0';i++){
			if(sen[i]=='I'){
				if(sen[i+1]=='V'||sen[i+1]=='X'){
					ans--;
				}
				else{
					ans++;
				}
			}
			if(sen[i]=='V'){
				ans+=5;
			}
			if(sen[i]=='X'){
				if(sen[i+1]=='L'||sen[i+1]=='C'){
					ans-=10;
				}
				else{
					ans+=10;
				}
			}
			if(sen[i]=='L'){
				ans+=50;
			}
			if(sen[i]=='C'){
				if(sen[i+1]=='D'||sen[i+1]=='M'){
					ans-=100;
				}
				else{
					ans+=100;
				}
			}
			if(sen[i]=='D'){
				ans+=500;
			}
			if(sen[i]=='M'){
				ans+=1000;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}