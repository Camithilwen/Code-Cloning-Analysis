#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int n;
int p[100];

int main(){
	cin >> n;
	rep(i, n * (n - 1) / 2){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a;
		--b;
		if(c == d){
			--p[a];
			--p[b];
		}
		else{
			if(c < d){
				swap(a, b);
			}
			p[a] -= 3;
		}
	}

	vector<int> v(p, p + n);
	sort(v.begin(), v.end());
	rep(i, n){
		cout << lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1 << endl;
	}
	return 0;
}