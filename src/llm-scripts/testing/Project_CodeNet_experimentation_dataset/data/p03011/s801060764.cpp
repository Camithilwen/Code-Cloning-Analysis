#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c, mn=100000; cin>> a >> b >> c;

	mn = min(b+a,mn);
	mn= min(b+c,mn);
	mn= min(a+c,mn);

	cout<<mn<<endl;
	return 0;
}