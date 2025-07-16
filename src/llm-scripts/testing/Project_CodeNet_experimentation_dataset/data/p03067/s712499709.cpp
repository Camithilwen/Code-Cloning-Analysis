#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main(){
	cin>>a>>b>>c;
	if (((a < c) && (b > c)) || ((a > c) && (b < c))){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
