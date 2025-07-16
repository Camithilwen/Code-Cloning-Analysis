#include<bits/stdc++.h>
using namespace std;
bool g[101][101];
int main(){
	int m,n;
	cin>>m>>n;
	cout<<"100 100"<<endl;
	for(int i=0;i<50;i++)
	for(int j=0;j<100;j++)
	g[i][j]=1;
	m--;
	for(int i=0;i<50;i+=2)
	for(int j=0;j<100;j+=2){
		if(m==0)
		break;
		g[i][j]=0;
		m--;
	}
	n--;
	for(int i=99;i>=50;i-=2)
	for(int j=0;j<100;j+=2){
		if(n==0)
		break;
		g[i][j]=1;
		n--;
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++)
		if(g[i][j]) cout<<"#";
		else
		cout<<".";
		cout<<endl;
	}
}