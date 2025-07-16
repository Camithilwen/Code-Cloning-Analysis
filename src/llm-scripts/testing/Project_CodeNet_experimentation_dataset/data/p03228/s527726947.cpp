#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);


    vector<ll> v(2); int k;
    cin>>v[0]>>v[1]>>k;


    for (int i=0; i<k; i++) {
	if (v[i%2]%2) {
	    v[i%2]--;
	} else {
	}
	int o = 1^(i%2);
	v[o] += (v[i%2]/2);
	v[i%2] /= 2;

    }

    cout<<v[0]<<" "<<v[1]<<endl;

    
    
    
    return 0;
}
