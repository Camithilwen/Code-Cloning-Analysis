#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int x,y; cin>>x>>y;
	int sum{};
	if(x==1&&y==1) sum += 400000;
	sum += max(0, 400000-x*100000);
	sum += max(0, 400000-y*100000);
	cout << sum << endl;
	
}
