#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000




int main(){
    
	int N;
	cin>>N;
	
	string S;
	cin>>S;
	
	for(int i=0;i<4;i++){
		string ans;
		if(i==0)ans="SS";
		if(i==1)ans="WW";
		if(i==2)ans="SW";
		if(i==3)ans="WS";
		
		for(int j=1;j<N+1;j++){
			char c = S[j%N];
			if(ans.back()=='W'){
				if(c=='o')c='x';
				else c='o';
			}
			if(c=='o'){
				ans += ans[ans.size()-2];
			}
			else{
				if(ans[ans.size()-2]=='W')ans+='S';
				else ans+='W';
			}

		}
		if(ans[0]==ans[N]&&ans[1]==ans[N+1]){
			cout<<ans.substr(0,N)<<endl;
			return 0;
		}
	}
	
	cout<<-1<<endl;
		
	
    return 0;
}

