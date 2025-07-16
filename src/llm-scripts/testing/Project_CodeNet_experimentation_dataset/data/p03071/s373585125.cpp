//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int a,b;
	cin>>a>>b;
	cout<<max(a+(a-1),max(b+(b-1),a+b))<<endl;	


	

	return 0;
}