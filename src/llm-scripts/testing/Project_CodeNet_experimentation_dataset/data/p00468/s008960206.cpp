#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n,m,x[10001],y[10001],c;
	bool tomo[600][600],party[600][2];
	while(true){
		memset(tomo,false,sizeof(tomo));
		memset(party,false,sizeof(party));
		cin>>n;
		cin>>m;
		c=0;
		if(n==0 && m==0){
			break;
		}
		for(int i=0;i<m;i++){
			cin>>x[i]>>y[i];
			tomo[x[i]][y[i]]=true;
			tomo[y[i]][x[i]]=true;
		}
		for(int i=2;i<=n;i++){
			if(tomo[1][i]==true){
				party[i][0]=true;
			}
		}
		for(int i=2;i<=n;i++){
			if(party[i][0]==true){
				for(int j=2;j<=n;j++){
					if(tomo[i][j]==true){
						party[j][1]=true;
					}
				}
			}
		}
		for(int i=2;i<=n;i++){
			if(party[i][0]==true || party[i][1]==true){
				c++;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}