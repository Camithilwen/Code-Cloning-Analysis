#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,h,w; cin>>n>>h>>w;
	cout<<(n-h+1)*(n-w+1)<<endl;
	return 0;
}
