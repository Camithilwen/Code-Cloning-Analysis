#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for(int i = 0; i < 4; i++){
    	ans.resize(n);
    	ans[0] = i%2;
    	ans[1] = i/2;
    	for(int j = 1; j < n-1; j++){
    		if(s[j] == 'o'){
    			if(ans[j] == 0) ans[j+1] = ans[j-1];
    			else ans[j+1] = !ans[j-1];
    		}
    		else{
    			if(ans[j] == 0) ans[j+1] = !ans[j-1];
    			else ans[j+1] = ans[j-1];
    		}
    	}
    	if(s[0] == 'o'){
    		if((ans[0] == 0) ^ (ans[1] == ans.back())) continue;
    	}
    	else{
    		if((ans[0] == 0) ^ (ans[1] != ans.back())) continue;
    	}
    	if(s.back() == 'o'){
    		if((ans.back() == 0) ^ (ans[0] == ans[n-2])) continue;
    	}
    	else{
    		if((ans.back() == 0) ^ (ans[0] != ans[n-2])) continue;
    	}
    	for(int j = 0; j < n; j++){
    		cout << "SW"[ans[j]];
    	}
    	cout << endl;
    	return 0;
    }
    cout << -1 << endl;
    return 0;
}