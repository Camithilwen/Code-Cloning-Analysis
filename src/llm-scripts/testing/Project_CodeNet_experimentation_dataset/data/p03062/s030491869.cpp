#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	bool f_zero = false;
	int num_m = 0;
	long long s = 0;
	int m = 1e9;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[i]==0) f_zero = true;
		if(a[i]<0) num_m++;
		s += abs(a[i]);
		m = min(m,abs(a[i]));
	}

	if(f_zero || num_m%2==0) cout << s << endl;
	else cout << s-2*m << endl;
}