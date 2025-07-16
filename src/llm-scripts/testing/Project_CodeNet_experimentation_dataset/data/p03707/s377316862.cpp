#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
bool a[2001][2001];
int res[2001][2001],v2[2001][2001],v1[2001][2001];
int main(){
	IOS
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		int cnt=0;
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			a[i][j+1]=s[j]-'0';
			if(a[i][j+1]==1){
				cnt++;
			}
			res[i][j+1]=cnt;
		}
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]==1&&a[i][j-1]==1){
				cnt++;
			}
			v1[i][j]=cnt;
		}
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1&&a[j-1][i]==1){
				cnt++;
			}
			v2[j][i]=cnt;
		}
	}
	for(int i=1;i<=q;i++){
		int x1,y1,x2,y2,r=0,v=0;
		cin>>x1>>y1>>x2>>y2;
		for(int j=y1;j<=y2;j++){
			r+=v2[x2][j]-v2[x1][j];
		}
		for(int j=x1;j<=x2;j++){
			r+=v1[j][y2]-v1[j][y1];
		}
		for(int j=x1;j<=x2;j++){
			v+=res[j][y2]-res[j][y1-1];
		}
		cout<<v-r<<endl;
	}
	return 0;
}
/*
 
*/