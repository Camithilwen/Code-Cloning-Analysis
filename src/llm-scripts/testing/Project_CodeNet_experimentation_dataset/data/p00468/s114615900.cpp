#include <iostream>
#include <queue>

using namespace std;



int main(){
	
	
	while(1){
		queue<int> Q;
		int n,m,a[10000][2],b,i,j,k;
		bool c[500]={};
		cin >> n >> m;
		if(n==0&&m==0){
			return 0;
		}
		for(j=0, i=0;i<m;i++){
			cin >> a[i][0] >> a[i][1];
			if(a[i][0]==1){
				c[a[i][1]-1]=true;
				Q.push(a[i][1]);
			}else if(a[i][1]==1){
				c[a[i][0]-1]=true;
				Q.push(a[i][0]);
			}
		}
		for(;Q.size()!=0;){
			b=Q.front();
			Q.pop();
			for(j=0;j<m;j++){
				if(b==a[j][0]){
					c[a[j][1]-1]=true;
				}
				if(b==a[j][1]){
					c[a[j][0]-1]=true;
				}
			}
		}
		int count=0;
		for(i=0;i<500;i++){
			if(c[i]==true){
				count++;
			}
		}
		cout << count-1 << "\n";
	}
}
	