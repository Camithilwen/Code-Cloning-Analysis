#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
  int n=5;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	int d; cin>>d;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(v[j]-v[i]>d){cout << ":(" << endl; return 0;}
		}
	}
	cout << "Yay!" << endl;
}