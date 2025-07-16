#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
string s;
int main(){
	cin >> s;
	if(s.size()<26){
		for(char c='a';c<='z';c++)
			if(s.find(c)==string::npos){
				cout << s << c;
				return 0;
			}
	}
	for(int i=s.size()-2;i>=0;i--){
		if(s[i]<s[i+1]){
			char t=s[i+1];
				for(int j=i+1;j<s.size();j++)
					if(s[j]>s[i])t=min(t,s[j]);
			s[i]=t;
			s=s.substr(0,i+1);
			cout << s;
			return 0;
		}
	}
	puts("-1");
	return 0;
}