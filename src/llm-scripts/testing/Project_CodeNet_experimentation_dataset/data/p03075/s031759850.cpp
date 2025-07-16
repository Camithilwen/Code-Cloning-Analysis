#include <bits/stdc++.h>
using namespace std;
int main(){
	int x[7];
	bool q=true;
	for(int i=0;i<6;i++){
		cin>>x[i];
	}
	if(x[4]-x[0]>x[5])q=false;
	if(q==true) cout<<"Yay!";
	else cout<<":(";
	cout<<"\n";
	return 0;
}