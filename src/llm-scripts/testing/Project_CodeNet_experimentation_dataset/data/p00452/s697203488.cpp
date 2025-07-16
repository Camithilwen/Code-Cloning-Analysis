#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m,i,j;
	while(cin >> n >> m, n && m){	
		int ret = 0;
		vector<int> data(n+1);
		vector<int> all;
		for(i=0;i<n;i++)cin >> data[i];
		for(i=0;i<n+1;i++)
			for(j=i;j<n+1;j++)
				all.push_back(data[i]+data[j]);
		sort(all.begin(),all.end());
		
		for(i=0;i<all.size();i++){
			int t = m-all[i];
			vector<int>::iterator it = upper_bound(all.begin(),all.end(),t);
			if(it != all.begin()){
				ret = max(ret,all[i] + *(it-1) );
			}
		}
		cout << ret << endl;
	}
}