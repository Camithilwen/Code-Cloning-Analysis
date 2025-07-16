#include<iostream>
#include<algorithm>
#include<set>
#define MAX 30
#include<string>
#include<vector>
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		int k;
		cin>>k;
		vector<string> vec;
		vector<int> ind;
		set<string> st;
		bool isDone[10001];
		for(int i=0;i<10001;i++){
			isDone[i] = false;
		}
		
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			vec.push_back(s);
			ind.push_back(i);
		}
		sort(vec.begin(),vec.end());
//		cout<<"---"<<endl;
		do{
			int hash = 0;
			for(int i=0;i<k;i++){
				hash = hash*10 + ind[i];
			}
			if(isDone[hash]) continue;
			isDone[hash] = true;
			string t="";
			for(int i=0;i<k;i++){
				t+=vec[ind[i]];
			}
			st.insert(t);
//			cout<<"------"<<endl;
		}while(next_permutation(ind.begin(),ind.end()));
		cout<<st.size()<<endl;
	}
	return 0;
}