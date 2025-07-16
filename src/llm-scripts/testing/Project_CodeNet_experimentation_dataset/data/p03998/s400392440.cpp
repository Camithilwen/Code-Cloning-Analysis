#include <bits/stdc++.h>
using namespace std;
int main() {
	queue<int> s[5];
	char winner;
	for(int i=0;i<3;i++) {
		string st;
		cin>>st;
		for(int j=0;j<(int)st.size();j++) s[i].push(st[j]-'a');
	}
	int now=0;
	while(1) {
		if(s[now].empty()) {winner=now+65;break;}
		int t=s[now].front();
		s[now].pop();
		now=t;
	}
	cout<<winner<<endl;
	return 0;
}