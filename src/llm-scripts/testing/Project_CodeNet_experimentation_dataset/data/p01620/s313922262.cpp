#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

string str="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char encode(char a,int k){
	int b;
	if(isupper(a))b=a-'A';
	else b=a-'a'+26;
	if(b-k>=0)return str[b-k];
	return str[52-abs(b-k)];
}

int main(void){
	
	int n;
	while(cin >> n,n){
		vector<int>k(n);
		for(int i=0;i<n;i++){
			cin >> k[i];
		}
		string s;
		cin >> s;
		for(int i=0;i<s.size();i++)s[i]=encode(s[i],k[i%n]);
		cout << s << endl;
	}
	
	return 0;
}