#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	multiset<int>s;
	s.insert(arr[0]);
	for(int i=1; i<n; i++){
		int val=arr[i];
		auto it=s.begin();
		int vals=(*it);
		if(val<=vals){
			s.insert(val);
			continue;
		}
		it=s.end();
		it--;
		vals=(*it);
		if(vals<val){
			s.erase(s.find(vals));
			s.insert(val);
			continue;
		}
		it=s.lower_bound(val);
		it--;
		s.erase(s.find((*it)));
		s.insert(val);
	}
	cout<<s.size();
	return 0;
}