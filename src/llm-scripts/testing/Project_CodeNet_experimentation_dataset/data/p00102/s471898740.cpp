#include <iostream>
#include<iomanip>

using namespace std;

int main() {
    
    int n;
    while (cin >> n) {
    
    if(n == 0)
    break;
    
    int A[51][51] = {};
    
    for(int i=0;i<n;i++) { 
    for(int j=0;j<n;j++) {
    	
    	cin >> A[i][j];
    	
    	A[i][n] += A[i][j];
    	A[n][j] += A[i][j];
	}
	A[n][n] += A[i][n];
}

	for(int i=0;i<=n;i++) { 
    for(int j=0;j<n;j++) {
    	
    	cout << setw(5)<< A[i][j];
    }
	cout << setw(5)<< A[i][n];
	cout << "\n";
}
}
    return 0;
}
