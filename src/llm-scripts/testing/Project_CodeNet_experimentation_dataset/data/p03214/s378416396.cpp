#include<bits/stdc++.h>
#include<boost/variant.hpp>
using namespace std;
typedef long long ll;
typedef vector<boost::variant<bool, ll, int, string, double, char*, const char*>> any;
template<typename T> inline void pr(const vector<T> &xs){
	for(int i=0; i<xs.size()-1; i++) cout<<xs[i]<<" ";
	(xs.empty()?cout:(cout<<xs[xs.size()-1]))<<endl;
}
#ifdef DEBUG
#define debug(...) pr(any{__VA_ARGS__})
#define debugv(x) pr((x))
#else
#define debug(...)
#define debugv(x)
#endif

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0; i<N; i++) cin >> A[i];

	int sum = 0;
	for(int i=0; i<N; i++) sum += A[i];

	int diff = abs(sum-N*A[0]);
	int idx = 0;
	for(int i=1; i<N; i++) {
		int d = abs(sum-N*A[i]);
		debug(i, d);
		if(d < diff){
			diff = d;
			idx = i;
		}
	}

	cout << idx << endl;

	return 0;
}
