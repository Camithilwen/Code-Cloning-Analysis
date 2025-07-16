#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t = 1; //cin >> t;
    while(t--){
    	int n;  cin >> n;
    	map<int,int> mp;
    	while(n--)
    	{
    		int x; cin >> x;
    		if(mp[x] == 0)
    			mp[x] = 1;
    		else mp[x] = 0;
    	}
    	int ans =  0;
    	for(auto x:mp)
    		if(x.second)
    			ans++;
    	cout << ans;
    	
    }    
}