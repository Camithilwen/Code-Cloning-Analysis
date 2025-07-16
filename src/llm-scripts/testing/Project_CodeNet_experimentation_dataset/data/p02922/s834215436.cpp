#include<bits/stdc++.h>
 
using namespace std;

#define debug(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;


int main()
{
    int has = 1, a, b, ans=0;
    cin >> a >> b;
	while(has < b){
		has--;
		has += a;
		ans++;
	}
	cout << ans << endl;
 
    return 0;
}
