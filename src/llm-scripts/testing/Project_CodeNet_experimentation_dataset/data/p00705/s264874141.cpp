#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main() {
  int n,q;
  while( cin >> n >> q, n|q) {
    map<int,int> mp;
    int maxi = -1;
    for(int i=0;i<n;++i) {
      int m;
      cin >> m;
      for(int j=0;j<m;++j) {
	int data;
	cin >> data ;
	++mp[data];
	maxi = max(mp[data],maxi);
      }
    }
    vector<int> vec;
    for(auto v : mp) {
      if( v.second >= q ) {
	if( maxi == v.second ) {
	  vec.push_back(v.first);
	}
      }
    }
    if( vec.size() ) {
      sort(vec.begin(),vec.end());
      cout<< vec[0] << endl;
    }else {
      cout << 0 << endl;
    }
  }
  return 0;
}