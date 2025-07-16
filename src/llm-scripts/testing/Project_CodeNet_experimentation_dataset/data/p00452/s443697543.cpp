#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n,m;
	while(cin>>n>>m&&!(n==0&&m==0)){
		int scores[1001];
		vector<int> comb;
		for(int i = 0; i < n; i++){
			cin>>scores[i];
		}
		scores[n]=0;
		for(int i = 0; i < n+1; i++){
			for(int j = 0; j < n+1; j++){
				int sum=scores[i]+scores[j];
				if(sum<=m)
					comb.push_back(sum);
			}
		}
		sort(comb.begin(),comb.end());
		comb.erase(unique(comb.begin(),comb.end()));

		int maxNum=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int left = (scores[i]+scores[j]);
				if(left<=m&&comb[0]+left<=m){
					vector<int>::iterator it = lower_bound(comb.begin(),comb.end(),m-left);
					if(it==comb.end()){
						maxNum=max(maxNum,comb[comb.size()-1]+left);
					}
					else{
						if(*it==(m-left)){
							maxNum=m;
						}
						else{
							it--;
							maxNum=max(maxNum,*it+left);
						}
					}
				}
			}
		}
		cout<<maxNum<<endl;
	}

	return 0;
}