#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	string s,t;cin>>s>>t;
	if(s==t)puts("0"),exit(0);
	reverse(s.begin(),s.end()),reverse(t.begin(),t.end());
	int k=0;
	queue<int>q;
	int ans=0;
	for(int i=0,j;i<n;i=j+1){
		for(j=i;j+1<n&&t[j+1]==t[j];++j);
		k=max(k,j);
		while(k<n&&t[i]!=s[k])++k;
		if(k==n)puts("-1"),exit(0);
		while(!q.empty()){
			int k1=q.front();
			if(k1+(int)q.size()<=j)q.pop();
			else break;
		}
		if(j<k)q.push(k);
		ans=max(ans,(int)q.size());
	}
	printf("%d\n",ans+1);
	return 0;
}