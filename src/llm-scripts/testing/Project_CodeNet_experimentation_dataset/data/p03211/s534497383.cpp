#include <bits/stdc++.h>
using namespace std;
int intinput() {
	int x;
	cin >> x;
	return x;
}
vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	vector<int> s(10);
	string ss;
	cin >> ss;
	for(int i = 0;i < ss.length();i++){
		s[i] = ss.at(i) - '0';
	}
	int cnt =100000;
	for(int i = 0;i < ss.length()-2;i++){
		if(100*s[i] + 10*s[i+1] + s[i+2] -753 <= 0){
			if((100*s[i] + 10*s[i+1] + s[i+2] - 753)*-1 < cnt){
				cnt = (100*s[i] + 10*s[i+1] + s[i+2] - 753)*-1;
			}
		}else{
			if(100*s[i] + 10*s[i+1] + s[i+2] - 753 < cnt){
				cnt = 100*s[i] + 10*s[i+1] + s[i+2] - 753;
			}
		}
	}
	cout << cnt << endl;
}