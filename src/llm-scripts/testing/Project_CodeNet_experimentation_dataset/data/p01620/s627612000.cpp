#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<string> ans;
vector<char> alp;

int main(){

	for(int i = 0;i < 26;i++){
		char a = 'a' + i;
		alp.push_back(a);
	}
	for(int i = 0;i < 26;i++){
		char  A = 'A' + i;
		alp.push_back(A);
	}

	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
		int k[100];
		for(int i = 0;i < n;i++) cin >> k[i];
		
		string s;
		cin >> s;
		
		for(int i = 0;i < s.size();i++){
			char cnum;
			if(s[i] >= 'a'){
				cnum = s[i] - 'a';
			}else cnum = s[i] - 'A' + 26;
			s[i] = alp[(cnum -k[i%n] +52)%52];
		}
		
		ans.push_back(s);
	}
	for(int i = 0;i < ans.size();i++)cout << ans[i] << endl;
	return 0;
}