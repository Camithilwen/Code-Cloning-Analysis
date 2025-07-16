#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n;
	vector<string> s(n);
	for(int i=0; i<n; i++){
		cin >> s.at(i);
	}
	cin >> m;
	vector<string> t(m);
	for(int i=0; i<m; i++){
		cin >> t.at(i);
	}
	vector<int> num(n);
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(s.at(i)==s.at(j)){
				num.at(i)++;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s.at(i)==t.at(j)){
				num.at(i)--;
			}
		}
	}
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	if(num.at(0)>=0){
		cout << num.at(0) << endl;
	}
	if(num.at(0)<0){
		cout << 0 << endl;
	}
}
