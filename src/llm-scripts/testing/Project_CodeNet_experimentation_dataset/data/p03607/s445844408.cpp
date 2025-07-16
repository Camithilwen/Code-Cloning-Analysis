#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin>>n;
	vector <int> v;
	for (int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	
	/*
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	*/
	int duplicate=0,no=0;
	for (int i=0;i<n;){
		if (v[i]==v[i+1]){
			duplicate++;
			i+=2;
		}
		else{
			i++;
			no++;
		}		
	}
	cout<<no<<endl;
	
	return 0;
}