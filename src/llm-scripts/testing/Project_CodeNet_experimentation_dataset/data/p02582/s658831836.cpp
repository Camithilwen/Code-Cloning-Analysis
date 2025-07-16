#include<bits/stdc++.h>
using namespace std;

main(){
	string s; cin>>s;
	
	int cnt=0, ans=0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='R') cnt++;
		else{
			ans = max(ans, cnt);
			cnt=0;
		}
	}
	ans = max(ans,cnt);
	cout<<ans;
}