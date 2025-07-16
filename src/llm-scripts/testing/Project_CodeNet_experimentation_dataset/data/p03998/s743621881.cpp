#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int turn,tmp;

int main(){
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	while(true){
		if(!s[turn].empty()){
			tmp = s[turn][0]-'a';
			s[turn].erase(s[turn].begin());
		}else{
			cout << static_cast<char>(turn+'A') << endl;
			return 0;
		}
		turn = tmp;
	}
}