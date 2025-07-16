#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define N 100100

lli n;

int main(void){
	cin >> n;
	vector<lli> v(n);
	vector<lli> e(N), o(N);
	rep(i, n) cin >> v[i];
	rep(i, n){
		if(i%2 == 0){
			e[v[i]]++;
		}else{
			o[v[i]]++;
		}
	}
	auto p1 = max_element(e.begin(), e.end())-e.begin();
	auto p2 = max_element(o.begin(), o.end())-o.begin();
	if(p1 != p2){
		cout << n-e[p1]-o[p2] << endl;
	}else{
		if(e[p1] < o[p2]){
			e[p1] = 0;
			lli ne = *max_element(e.begin(), e.end());
			cout << n-ne-o[p2] << endl;
		}else if(e[p1] == o[p2]){
			lli tmp = e[p1];
			e[p1] = o[p2] = 0;
			lli noe = max(*max_element(e.begin(), e.end()), 
			*max_element(o.begin(), o.end()));
			cout << n-tmp-noe << endl;
		}else{
			o[p2] = 0;
			lli no = *max_element(o.begin(), o.end());
			cout << n-e[p1]-no << endl;
		}
	}

	return 0;
}
