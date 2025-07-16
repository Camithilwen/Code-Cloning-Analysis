//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int A,B,C,D,E,F;
int X[10001],Y[10001];
int main() {
	cin>>A>>B>>C>>D>>E>>F;

	int S,T;
	S=A;
	T=E;
	if(S>B)S=B;
	if(S>C)S=C;
	if(S>D)S=D;
	if(T>F)T=F;
	int R=A+B+C+D+E+F;
	cout<<R-S-T<<endl;
	return 0;
}