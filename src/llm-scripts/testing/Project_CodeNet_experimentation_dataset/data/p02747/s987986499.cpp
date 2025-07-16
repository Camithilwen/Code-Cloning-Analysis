#include<bits/stdc++.h>
#include<boost/variant.hpp>
using namespace std;
typedef long long ll;
typedef vector<boost::variant<bool, ll, int, string, double, char*, const char*>> anys;
template<typename T> inline void pr(const vector<T> &xs){
	for(int i=0; i<xs.size()-1; i++) cout<<xs[i]<<" ";
	(xs.empty()?cout:(cout<<xs[xs.size()-1]))<<endl;
}
#ifdef DEBUG
#define debug(...) pr(anys{__VA_ARGS__})
#define debugv(x) pr((x))
#else
#define debug(...)
#define debugv(x)
#endif

int main(){
	string S;
	cin >> S;
	string ans = S.size()%2==0 ? "Yes" : "No";
	for(int i=0; i<S.size(); i++){
		if(S[i]!=(i%2==0?'h':'i')) ans = "No";
	}
	cout << ans << endl;

	return 0;
}
