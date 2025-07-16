#include<iostream>
#include<ctype.h>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
string s,ss;
queue<int> q;
bool vis[200];
int main(){
	int l;cin>>l;int er=l,ans=0;
	cin>>s>>ss;
	if(s==ss)goto portal0;
	if(s[0]!=ss[0])goto portalfail;
	for(int i=0;i<l;++i)vis[s[i]-'a']=1; 
	for(int i=0;i<l;++i)if(!vis[ss[i]-'a'])goto portalfail;
	
	for(int i=er-1;i>=0;--i){
		if(i && ss[i-1]==ss[i])goto go;
		er=min(er,i);
		while(er>=0 && s[er]!=ss[i])--er;
		if(er<0)goto portalfail;
		while(!q.empty() && q.front()>=i+q.size())q.pop();
		q.push(er);
		if(i!=er)ans=max(ans,int(q.size()));
		go:
			;
	} 
	printf("%d",ans+1);
	return 0;
	portal0:
		printf("0\n");
	return 0;
	portalfail:
		printf("-1\n");
	return 0;
}
