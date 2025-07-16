//
//  main.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,cards[11];
bool selected[11];
vector<vector<int>> selectlist;
vector<int> makelist;

void reset(){
	n = k = 0;
	selectlist.clear();
	makelist.clear();
	for(int i=0;i<11;i++){
		cards[i] = 0;
		selected[i] = false;
	}
}

void select_dfs_(int depth,int top,vector<int> vec){
	if(depth == k){
		selectlist.push_back(vec);
		return;
	}
	for(int i=top+1;i<n;i++){
		vec.push_back(cards[i]);
		select_dfs_(depth+1,i,vec);
		vec.pop_back();
	}
}

void makeint_dfs_(int depth,int makedint,vector<int> source){
	if(depth == k){
		makelist.push_back(makedint);
		return;
	}
	for(int i=0;i<k;i++){
		if(!selected[i]){
			selected[i] = true;
			int maked;
			if(source[i]/10 > 0){
				maked = makedint*100+source[i];
			}else{
				maked = makedint*10+source[i];
			}
			makeint_dfs_(depth+1,maked,source);
			selected[i] = false;
		}
	}
}

int main(){
	while(1){
		reset();
		
		cin >> n >> k;
		if(n == 0 && k == 0)break;
		for(int i=0;i<n;i++){
			cin >> cards[i];
		}
		
		for(int i=0;i<n-k+1;i++){
			vector<int> vec;
			vec.push_back(cards[i]);
			select_dfs_(1,i,vec);
		}
		
		for(int i=0;i<selectlist.size();i++){
			for(int j=0;j<selectlist[i].size();j++){
				selected[j] = true;
				makeint_dfs_(1,selectlist[i][j],selectlist[i]);
				selected[j] = false;
			}
		}
		
		sort(makelist.begin(),makelist.end());
		
		int answer=0,memo=-1;
		for(int i=0;i<makelist.size();i++){
			if(memo != makelist[i]){
				answer ++;
				memo = makelist[i];
			}
		}
		
		cout << answer << endl;
		
	}
	
	return 0;
}