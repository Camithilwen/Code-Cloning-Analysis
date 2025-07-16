#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int n;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    multiset<int> ms;
    ms.insert(0);ms.insert(0);ms.insert(0);
    
    ll res = 1;

    for (int i=0; i<n; i++) {
	res=res*ms.count(a[i])%mod;
	if (res==0) out(0);
	ms.erase(ms.find(a[i]));
	ms.insert(a[i]+1);
    }
    cout<<res<<endl;    
    return 0;
}
