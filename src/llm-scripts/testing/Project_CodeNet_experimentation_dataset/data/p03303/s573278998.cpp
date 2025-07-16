#include <bits/stdc++.h>
using namespace std;
string a;
int b;
int main(){
	cin>>a>>b;
	for(int i=0;i<a.size();i+=b)
		cout<<a[i];
	return 0;
}