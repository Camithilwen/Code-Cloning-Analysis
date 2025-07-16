#include <bits/stdc++.h>
#define nmax 100005

using namespace std;

string s; 
int n,ans[nmax];

bool check(){
	for(int i=2;i<n;i++){
		if((ans[i-1]==0)){
			if((s[i-1]=='o'))
				ans[i]=ans[i-2];
			else
				ans[i]=1-ans[i-2];
		}
		else{
			if(s[i-1]=='o')
				ans[i]=1-ans[i-2];
			else
				ans[i]=ans[i-2];
		}
	}
	if(ans[0]==0){
		if(s[0]=='o' && (ans[n-1]!=ans[1])){
			return 0;
		}
		if(s[0]=='x' && (ans[n-1]==ans[1])){
			return 0;
		}
	}
	else{
		if(s[0]=='x' && (ans[n-1]!=ans[1])){
			return 0;
		}
		if(s[0]=='o' && (ans[n-1]==ans[1])){
			return 0;
		}
	}
	if(ans[n-1]==0){
		if(s[n-1]=='o' && (ans[n-2]!=ans[0])){
			return 0;
		}
		if(s[n-1]=='x' && (ans[n-2]==ans[0])){
			return 0;
		}
	}
	else{
		if(s[n-1]=='x' && (ans[n-2]!=ans[0])){
			return 0;
		}
		if(s[n-1]=='o' && (ans[n-2]==ans[0])){
			return 0;
		}
	}
	return 1;
}

int main(){
	cin >> n;
	cin >> s;
	bool flag=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ans[0]=i;
			ans[1]=j;
			if(check()){
				flag=1;
				break;
			}
		}
		if(flag){
			break;
		}
	}
	if(!flag){
		cout << -1 << endl;
	}
	else{
		for(int i=0;i<n;i++){
			if(!ans[i]){
				cout << 'S';
			}
			else{
				cout << 'W';
			}
		}
	}
	cout << endl;
	return 0; 
}