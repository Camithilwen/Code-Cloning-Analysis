#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n;
	int i , j;
	while(cin >> n, n!=0) {
	int arr[10][10]={0,0};
	int ansW[11]={0};
	int ansH[11]={0};
		for(i=0 ; i<n ; i++){
			for(j=0 ; j <n ; j++){
				cin >>arr[i][j];
			}
		}
		for(i=0 ; i<n ; i++){
			for(j=0 ; j<n ; j++){
				ansH[i]+=arr[i][j];
			}
		}
		for(i=0 ; i<n ; i++){
			for(j=0 ; j<n ; j++){
				ansW[i]+=arr[j][i];
			}
		}
		for(i=0 ; i<n ; i++){
			for(j=0 ; j<n ; j++){
				cout.fill(' ');
				cout << setw(5) <<right <<arr[i][j];
			}
			cout << setw(5) <<right <<ansH[i] << endl;
		}
		for(i=0; i<n ; i++){
				ansW[n]+=ansW[i];
		}
		for(i=0 ; i<n+1 ; i++){
			cout << setw(5) <<right << ansW[i];
		}
		cout << endl;
	}
	return 0;
}