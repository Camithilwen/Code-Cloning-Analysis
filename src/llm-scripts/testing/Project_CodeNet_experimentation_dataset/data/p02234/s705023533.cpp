// http://algorithms.blog55.fc2.com/blog-entry-66.html

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#define M 100

int N,R[M+1],C[M][M],B[M][M];

void compute(){
	int i=0,j,k,cost;
	memset(C,99,sizeof(C));
	for(;i<N;i++)C[i][i]=0;
	for(j=1;j<N;j++)
		for(i=0;i<N - j; i++ )
			for (k = i; k < i + j; k++ ){
				cost = C[i][k] + C[k+1][i+j] + R[i]*R[k+1]*R[i+j+1];
				if(cost<C[i][i+j])C[i][i+j]=cost,B[i][i+j]=k; 
			}
}

void order( int i, int j ){
	if ( i == j ) cout << "M" << i;
	else{
		cout << "(";
		order( i, B[i][j]-1 ); order(B[i][j], j);
		cout << ")";
	}
}

void input(){
	cin >> N;
	int z,i=0;
	for (; i < N; i++ ) cin >> R[i]>>z;
	R[i]=z;
	//SIZE++;
}

void output(){
	cout <<  C[0][N-1] << endl;
	//order(0, N);
	//cout << endl;
}

main(){
	input();
	compute();
	output();
}