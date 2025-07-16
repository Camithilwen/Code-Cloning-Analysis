#include <bits/stdc++.h>
#define lop(i, n) for (int i = 0; i < (n); ++i)
#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    int a1 = a + b;
    int a2 = a + c;
    int a3 = b + c;
    if (a1 <= a2 && a1 <= a3) {
        cout<<(a1);
    } else if (a2 <= a1 && a2 <= a3) {
        cout<<(a2);
    } else if (a3 <= a1 && a3 <= a2) {
        cout<<(a3);
    }



}