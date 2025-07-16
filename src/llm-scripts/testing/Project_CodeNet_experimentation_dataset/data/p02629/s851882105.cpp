#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;
lli pow1(lli a,lli b){
	lli out = 1;
	for(int i = 0;i < b;++i) out = out * a;
	return out;
}

void solve(){
	lli n;
	cin >> n;
	n = n - 1;
	vector <lli> a;
	for(int i = 0;i <= 11;++i) a.push_back(26ll * (pow1(26ll,i) - 1) / 25);
	int len = upper_bound(a.begin(),a.end(),n) - a.begin();
	n = n - a[len - 1];
	string out = "";
	for(int i = 1;i <= len;++i){
		lli k = pow1(26ll,len - i);
		out += 'a' + n / k;
		n = n % k;
	}
	//reverse(out.begin(),out.end());
	cout << out << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
