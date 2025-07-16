#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int i;
	int n;
	cin>>n;
	int a[n],b[n];
	for (i = 0 ; i < n ; i++) cin>>a[i];
	for (i = 0 ; i < n ; i++) cin>>b[i];
	int s[3*n+2];
	s[0] = -2;
	for (i = 1; i < n+1 ; i++) s[i] = b[i-1]^b[i%n];
	s[n+1] = -1;
	for (i = n+2; i < 2*n+2 ; i++) s[i] = a[i-n-2]^a[(i-n-1)%n];
	for (i = 2*n+2; i < 3*n+2 ; i++) s[i] = s[i-n];
	//for (i = 0; i < 3*n+2; i++) cout<<s[i]<<" ";
	int P[3*n+2];
	P[1] = 0;
	for (i = 2; i < 3*n+1; i++){
		int ps = P[i-1];
		while (s[i] != s[ps+1] && ps) ps = P[ps];
		if (s[i] == s[ps+1]) P[i] = ps+1;
		else P[i] = 0;
		if (P[i] == n) cout<<i-2*n-1<<" "<<(b[0]^a[i-2*n-1])<<"\n";
	}
    return 0;
}
