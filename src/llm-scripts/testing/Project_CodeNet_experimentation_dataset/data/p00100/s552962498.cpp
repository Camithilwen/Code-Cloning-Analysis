#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, id[4001], p, s;
	bool a[4001], f;
	long long int t, u, b[4001];
	
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		fill(a, a+4001, false);
		fill(b, b+4001, 0);
		p = 0;
		
		for(int i = 0; i < n; i++){
			cin >> s >> t >> u;
			b[s] += t * u;
			if(a[s]){
				continue;
			}
			id[p++] = s;
			a[s] = true;
		}
		f = true;
		for(int i = 0; i < p; i++){
			if(b[id[i]] >= 1000000){
				cout << id[i] << endl;
				f = false;
			}
		}
		
		if(f){
			cout << "NA" << endl;
		}
	}
	
	return 0;
}