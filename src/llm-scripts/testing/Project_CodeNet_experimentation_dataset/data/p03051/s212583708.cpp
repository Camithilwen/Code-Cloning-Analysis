#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002



int main(){
	
	int N;
	cin>>N;
	
	vector<int> A(N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	
	for(int i=1;i<N;i++)A[i] ^= A[i-1];
	
	vector<vector<int>> ind(1<<20,vector<int>());
	
	for(int i=0;i<N;i++){
		ind[A[i]].push_back(i);
	}
	
	int ans = 0;
	if(A.back()==0){
		int t = 1;
		for(int i=0;i<ind[0].size()-1;i++){
			t = mod(t * 2);
		}
		ans = mod(ans + t);
	}
	
	for(int i=1;i<(1<<20);i++){
		if(A.back()!=0&&A.back()!=i)continue;

		int sum = 0;
		int dp_sum = 0;
		for(int j=0;j<ind[i].size();j++){
			if(j==0){
				//sum += 1;
				dp_sum += 1;
			}
			else{
				int t = distance(lower_bound(ind[0].begin(),ind[0].end(),ind[i][j-1]),lower_bound(ind[0].begin(),ind[0].end(),ind[i][j]));
				int dp = mod(sum + mod(dp_sum * t));
				sum = dp;
				dp = mod(dp + 1);
				
				dp_sum = mod(dp_sum + dp);
			}
		}
		
		if(A.back()==0){
			ans = mod(ans + dp_sum);
		}
		else{
			ans = mod(ans + sum + 1);
		}
		
	}
	
	cout<<ans<<endl;
		

	return 0;
}