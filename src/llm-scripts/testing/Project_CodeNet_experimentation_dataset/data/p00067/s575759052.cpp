#include<iostream>
#include<cstdio>
using namespace std;
char s[20][20];
int ans,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void func(int y,int x){
	s[y][x]='0';
	int q,p;
	for(int i=0;i<4;i++){
		q=x+dx[i];
		p=y+dy[i];
		if(q>=0&&q<12&&p>=0&&p<12){
			if(s[p][q]=='1')
			func(p,q);
		}
	}
}
int main(){
	
	while(cin>>s[0]){
		ans=0;
		for(int i=1;i<12;i++)
		cin>>s[i];
		for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)
		if(s[i][j]=='1'){
			ans++;
			func(i,j);
		}
		cout<<ans<<endl;
	}
	return 0;
}	