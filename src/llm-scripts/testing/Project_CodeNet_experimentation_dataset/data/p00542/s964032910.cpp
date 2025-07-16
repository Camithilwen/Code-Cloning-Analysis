//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct pair<int,int> P;
int A,B,C,D,E,F;
int main() {
	cin>>A>>B>>C>>D>>E>>F;

	int M=A;
	if(B<M)M=B;
	if(C<M)M=C;
	if(D<M)M=D;
	int R=A+B+C+D-M;
	int L=0;
	if(E<F){
		L=F;
	}else{
		L=E;
	}

	cout<<R+L<<endl;
	return 0;
}