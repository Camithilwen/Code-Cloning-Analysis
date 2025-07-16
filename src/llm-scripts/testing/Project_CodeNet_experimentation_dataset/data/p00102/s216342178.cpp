#include <iostream>
using namespace std;
int main(void)
{
	int n;
	while(cin>>n){
		int date[11][11]={0};
		if(!n) break;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> date[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0; j<n; j++){
				date[i][n] += date[i][j];
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0; j<n; j++){
				date[n][i] += date[j][i];
			}
		}
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				printf("%5d",date[i][j]);
			}
			cout << "\n";
		}
	}
	return 0;
}