#include <bits/stdc++.h>
using namespace std;


string t1;
int main(){
	for(int i = 0 ; i < 26 ; i++) t1 += 'a'+i,t1 += 'A'+i;
	sort(t1.begin(),t1.end());
	rotate(t1.begin(),t1.begin()+26,t1.end());
	int n;
	while(cin >> n && n){
		vector<int> k(n);
		string s;
		for(int i = 0 ; i < n ; i++) cin >> k[i];
		cin >> s;
		for(int i = 0 ; i < s.size() ; i++){
			int p = k[i%n];
			int pos = t1.find(s[i]);
			int hoge = (pos - p) % 52 + 52;
			hoge %= 52;
			cout << t1[hoge];
		}
		cout << endl;
	}
}