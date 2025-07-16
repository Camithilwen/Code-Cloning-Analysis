#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int t[12][12];

int main(void){
	while(cin>>n,n){
		memset(t,0,sizeof(t));
		for(int i=0;i<=n;i++){
			for(int j=0;j<n;j++){
				if(i != n){
					cin>>t[i][j];
					t[n][j] += t[i][j];
				}
				t[i][n] += t[i][j];
			}
		}

		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				printf("%5d",t[i][j]);
			}
			cout<<endl;
		}
	}

	return 0;
}