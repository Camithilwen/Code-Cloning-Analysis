#include<cstdio>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cstdlib>

using namespace std;

int main(){
	while(1){
		int n,k;
		scanf("%d%d",&n,&k);
		
		if(n==0)
			break;
		
		vector<int> card(n);
		for(int i=0;i<n;i++){
			scanf("%d",&card[i]);
		}
		
		sort(card.begin(),card.end());
		
		vector<int> data;
		do{
			
			stringstream sst;
			for(int i=0;i<k;i++){
				sst<<card[i];
			}
			data.push_back(atoi(sst.str().c_str()));
			
			
			reverse( card.begin()+k,card.end());
		}while( next_permutation(card.begin(),card.end()) );
		
		sort(data.begin(),data.end());
		
		
		printf("%d\n",distance(data.begin(),unique(data.begin(),data.end())) );
	}
}