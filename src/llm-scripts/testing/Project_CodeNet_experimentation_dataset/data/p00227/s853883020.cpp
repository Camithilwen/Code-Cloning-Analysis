#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	while(cin >> n >> m,n){
		int p[1000],sum = 0;
		for(int i = 0;i < n;i++) cin >> p[i];
		sort(p,p + n,greater<int>());
		for(int i = 0;i < n;i++){
			if(i % m != m - 1) sum += p[i];
		}
		cout << sum << endl;
	}
	return 0;
}