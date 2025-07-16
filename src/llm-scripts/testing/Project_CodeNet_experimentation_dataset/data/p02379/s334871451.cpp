#include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b,c,d,e,f,g,h=0;
	cin>>a>>b>>c>>d;
	e=c-a;
	f=d-b;
	g=e*e+f*f;
	h=sqrt(g);
	cout <<setprecision(12)<<h <<endl;
	return 0;
}