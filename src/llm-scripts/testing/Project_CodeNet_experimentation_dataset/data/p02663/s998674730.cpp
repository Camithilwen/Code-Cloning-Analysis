#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll h1,m1,h2,m2,k;
	cin>>h1>>m1>>h2>>m2>>k;
	ll t=((h2-h1)*60)-m1+m2;
	ll d=t-k;
	if(d<=0){
		cout<<"0"<<"\n";
	}
	else{
		cout<<d<<"\n";
	}
	return 0;
}