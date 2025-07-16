#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main(){
	int N,M;
	while(cin>>N>>M,N||M){
		int latte[1001],ans=0;
		vector<int> comb;
		latte[0]=0;
		for(int i=1;i<=N;i++){
			cin>>latte[i];
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				comb.push_back(latte[i]+latte[j]);
			}
		}
		sort(comb.begin(),comb.end());
		//for(int i=0;i<comb.size();i++) printf("%d ",comb[i]); puts("");
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				vector<int>::iterator itr;
				itr = upper_bound(comb.begin(),comb.end(),M-latte[i]-latte[j]);
				if(itr!=comb.begin()) ans = max(ans,latte[i]+latte[j]+*(itr-1));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}