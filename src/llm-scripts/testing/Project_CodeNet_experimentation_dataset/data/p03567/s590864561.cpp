#include<bits/stdc++.h>
using namespace std;
int main() {
	bool A=0;
	char ch,ch_;
	cin>>ch;
	ch_=ch;
	while((cin>>ch)!=0) {
		if(ch_=='A'&&ch=='C') {
			cout<<"Yes";
			return 0;
		}
		ch_=ch;
	}
	cout<<"No";
	return 0;
}