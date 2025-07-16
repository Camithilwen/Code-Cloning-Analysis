//
//  main.cpp

#include <iostream>
#include <vector>
using namespace std;


int main(){	
	int n,m;
	int A[1001]={},B[1001]={};
	vector<pair<int,int> > vec;
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> A[i];
//		vec.push_back(make_pair(A[i],i));
	}
	for(int i=0;i<m;i++){
		cin >> B[i];
	}
	
//	sort(vec.begin(),vec.end(),greater<pair<int,int> >());
	int answer[1001]={};
	
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(A[i] <= B[j]){
				answer[i] ++;
				break;
			}
		}
	}
	int Max = -1;
	for(int i=0;i<n;i++){
		Max = max(Max,answer[i]);
	}
	for(int i=0;i<n;i++){
		if(Max == answer[i]){
			cout << i+1 << endl;
			break;
		}
	}
	
	return 0;
}