#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	long long int n , id , price , num, cnt;
	while(cin >> n , n!=0){
		vector<long long int> p(4001,0);
		vector<int> a;
		while(n--){
			cin>>id>>price>>num;
			if(find(a.begin(),a.end(),id)==a.end()) a.push_back(id);
			p[id]+=price*num;
			}
		cnt=0;	
		for(int i=0;i<a.size();i++){
			if(p[a[i]]>=1000000){
				cout << a[i] << endl; 
				cnt++;
			} 
		}
		if (cnt==0) cout << "NA" << endl;
	}
	return 0;
}