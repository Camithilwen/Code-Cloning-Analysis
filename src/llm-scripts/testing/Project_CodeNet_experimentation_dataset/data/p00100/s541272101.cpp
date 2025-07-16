#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	long long n,i,p,q;
	while(cin>>n,n){
		vector<int> ids;
		map<int,long long> m;
		while(n--){
			cin>>i>>p>>q;
			if(!m.count(i))ids.push_back(i);
			m[i]+=p*q;
		}
		int na=1;
		for (int k=0;k<(int)ids.size();++k) {
			if(1000000<=m[ids[k]]){
				cout<<ids[k]<<endl;
				na=0;
			}
		}
		if(na) cout<<"NA\n";
	}
}