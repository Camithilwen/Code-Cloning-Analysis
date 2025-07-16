#include<iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,a,b,c,d;
    cin >> n;

	int A[1000];
	int B[1000]; 


	for (int i=0; i<n; i++){
		A[i] = 0;
		B[i] = 0;
	}


	for(int i=0; i<n*(n-1)/2; i++){
		cin >> a >> b >> c >> d;
		if( c > d ){
			A[a-1] += 3;
			B[a-1] += 3;
		}
		else if( c < d ){
			A[b-1] += 3;
			B[b-1] += 3;
		}
		else{
			A[a-1] ++;
			A[b-1] ++;
			B[a-1] ++;
			B[b-1] ++;
		}
	}

	sort(A,A+1000);
	reverse(A,A+1000);

	int x = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			x++;
			if(B[i] == A[j]){
				cout << x << endl;
				x = 0;
				break;
			}
			
		}
	}

	return 0;
}

