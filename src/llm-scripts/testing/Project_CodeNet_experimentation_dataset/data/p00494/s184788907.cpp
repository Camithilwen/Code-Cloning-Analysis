#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cl[1000000][2];
int main(void){
	ll i,len,lv,cnt,p,pp,x;
	char s[1000001];
	cin>>s;
	len=strlen(s);
	for(i=0;i<len;i++) cl[i][1]=0;
	cnt=1; p=0; pp=0;
	if(s[0]=='J') cl[0][0]=0;
	else if(s[0]=='O') cl[0][0]=1;
	else cl[0][0]=2;
	for(i=0;i<len;i++){
		if(s[pp]!=s[i]){
			p++; pp=i;
			if(s[pp]=='J') cl[p][0]=0;
			else if(s[pp]=='O') cl[p][0]=1;
			else cl[p][0]=2;
		}
		cl[p][1]++;
	}
/*	for(i=0;i<=p;i++) cout<<cl[i][1]<<' ';
	cout<<endl;*/
	lv=0;
	for(i=1;i<len-1;i++){
		if(cl[i][0]==1){
			x=cl[i][1];
			if(cl[i-1][0]==0&&cl[i+1][0]==2){
				if(cl[i-1][1]>=x&&cl[i+1][1]>=x) lv=max(lv,x);
			}
		}
	}
	cout<<lv<<endl;
	return 0;
}
