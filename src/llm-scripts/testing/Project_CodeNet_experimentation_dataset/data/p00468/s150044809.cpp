#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(void){
	int n,m;
	while(cin>>n>>m,n||m){
		vector<set<int> > friends(n+1);
		for(int i=0,a,b;i<m;++i){
			cin>>a>>b;
			friends[a].insert(b);friends[b].insert(a);
		}
		set<int> myfriends;
		for(set<int>::iterator it=friends[1].begin();it!=friends[1].end();++it){
			for(set<int>::iterator it2=friends[*it].begin();it2!=friends[*it].end();++it2){
				myfriends.insert(*it2);
			}
			myfriends.insert(*it);
		}
		int ans=((myfriends.find(1)!=myfriends.end())?myfriends.size()-1:myfriends.size());
		cout<<ans<<endl;
	}
	return 0;
}