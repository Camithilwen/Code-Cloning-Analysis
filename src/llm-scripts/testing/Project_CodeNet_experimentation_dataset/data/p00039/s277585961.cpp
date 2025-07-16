#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
using namespace std;

int main(){
	char s[105];

	while(scanf("%s",s)!=EOF){
		int len,n[105]={},ans=0;
		len=strlen(s);
		rep(i,0,len){
			if(s[i]=='I') n[i]=1;
			else if(s[i]=='V') n[i]=5;
			else if(s[i]=='X') n[i]=10;
			else if(s[i]=='L') n[i]=50;
			else if(s[i]=='C') n[i]=100;
			else if(s[i]=='D') n[i]=500;
			else if(s[i]=='M') n[i]=1000;
		}
		rep(i,0,len-1){
			if(n[i]<n[i+1]) ans-=n[i];
			else ans+=n[i];
		}
		ans+=n[len-1];
		cout<<ans<<endl;
	}
}