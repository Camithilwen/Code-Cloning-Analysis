#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int a,b,s,i,x;
	s=100;
	x=0;
	for(i=0;i<4;i++){
		cin>>a;
		if(s>a) s=a;
		x=x+a;
	}
	x=x-s;
	s=100;
	for(i=0;i<2;i++){
		cin>>b;
		if(s>b) s=b;
		x=x+b;
	}
	x=x-s;
	cout<<x<<endl;
	return 0;
}
