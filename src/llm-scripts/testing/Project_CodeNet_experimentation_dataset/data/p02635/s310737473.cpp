#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

void ruiseki(vector<int> &sum){
	for(int i=1;i<sum.size();i++){
		sum[i] = mod(sum[i] + sum[i-1]);
	}
}

int main(){
	
	string S;
	cin>>S;
	
	int K;
	cin>>K;
	
	K = min(K,400);
	while(S.size()!=0&&S.back()=='0'){
		S.pop_back();
	}
	
	if(S.size()==1){
		cout<<1<<endl;
		return 0;
	}
	
	vector<int> num;
	
	for(int i=0;i<S.size();i++){
		if(S[i]=='0'){
			int c = 0;
			for(int j=i+1;j<S.size();j++){
				if(S[j]=='0')break;
				c++;
			}
			num.push_back(c);
		}
	}
	
	if(S[0]=='0')num.insert(num.begin(),0);
	else{
		int c = 0;
		for(int i=0;i<S.size();i++){
			if(S[i]=='0'){
				c++;
				if(i+1==S.size()){
					cout<<1<<endl;
					return 0;
				}
			}
			else{
				break;
			}
		}
		num.insert(num.begin(),c);
	}
	
	reverse(num.begin(),num.end());
	
	vector<vector<vector<int>>> dp(num.size()+1,vector<vector<int>>(K+1,vector<int>(S.size()+1,0)));
	dp[0][0][0] = 1;
	
	vector<vector<vector<int>>> sum = dp;
	ruiseki(sum[0][0]);
	
	for(int i=1;i<=num.size();i++){
		for(int j=0;j<=K;j++){
			for(int k=0;k<=S.size();k++){
				dp[i][j][k] = mod(sum[i-1][j].back() - sum[i-1][j][k]);
				
				for(int t=0;t<=num[i-1];t++){
					if(j-t<0||k-t<0)break;
					dp[i][j][k] = mod(dp[i][j][k] + dp[i-1][j-t][k-t]);
				}
				sum[i][j][k] = dp[i][j][k];
			}
			ruiseki(sum[i][j]);
		}
	}
	int ans = 0;
	for(int i=0;i<=K;i++){
		ans = mod(ans + dp.back()[i][0]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}