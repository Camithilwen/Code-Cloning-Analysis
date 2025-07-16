#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int n;
int k;

vector<int> card;
set< string > cd;
set< vector<int> > ccd;

/*
string IteratorToString(vector<int>::iterator begin, vector<int>::iterator end){
	string str = "";
	char ch[256];
	for(;begin < end;begin++){
		sprintf(ch,"%d",*begin);
		str += ch;
	}
	return str;
}
*/
string VectorToString(const vector<int> &vec){
	string str = "";
	for(int i=0;i<vec.size();i++){
		char ch[256];
		sprintf(ch,"%d",vec[i]);
		str += ch;
	}
	return str;
}

string VectorToDebugText(const vector<int> &vec){
	string str = "";
	for(int i=0;i<vec.size();i++){
		char ch[256];
		sprintf(ch,"%d",vec[i]);
		str += ch;
		str += ":";
	}
	return str;
}

void solve(int a,vector<int> v){
	if(v.size() == k){
		sort(v.begin(),v.end());
		ccd.insert(v);
		return;
	}
	if(a == n){return;}
	solve(a + 1,v);
	v.push_back(card[a]);
	solve(a + 1,v);
}


int main(){
	while(1){
		int self;
		scanf("%d %d",&n,&k);
		if(n == 0 && k == 0){
			break;
		}
		card.clear();
		cd.clear();
		ccd.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&self);
			card.push_back(self);
		}
		vector<int> cc(k);
	
		sort(card.begin(),card.end());
		/*
		while(next_permutation(card.begin(),card.end())){
			 cd.insert(VectorToString(card.begin(),card.begin()+k));
		}
		*/
		solve(0,vector<int>());
		for(set<vector<int> >::iterator it = ccd.begin();it != ccd.end();it++){
			vector<int> vec = *it;
			sort(vec.begin(),vec.end());
			cd.insert(VectorToString(vec));
			//printf("[%s]\n",VectorToDebugText(vec).c_str());
			while(next_permutation(vec.begin(),vec.end())){
				//printf("%s\n",VectorToDebugText(vec).c_str());
				//printf("%s\n",VectorToString(vec).c_str());
				cd.insert(VectorToString(vec));
			}
		}
		printf("%d\n",cd.size());
	}
}