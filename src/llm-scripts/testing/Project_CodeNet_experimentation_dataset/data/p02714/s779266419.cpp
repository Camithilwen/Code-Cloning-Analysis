#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;

int r[N],g[N],b[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	ll ans = 0;
	
	if(s[0] == 'R')r[0]++;
	if(s[0] == 'G')g[0]++;
	if(s[0] == 'B')b[0]++;
	
	for(int i=1;i<n;i++){
		r[i] = r[i-1];
		g[i] = g[i-1];
		b[i] = b[i-1];
		if(s[i] == 'R')r[i]++;
		if(s[i] == 'G')g[i]++;
		if(s[i] == 'B')b[i]++;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[i] != s[j]){
				if(s[i] != 'G' && s[j] != 'G'){
					ans += g[n-1]-g[j];
					if(j + (j-i) <= n-1 && s[j+j-i] == 'G')ans--;
				}
				if(s[i] != 'R' && s[j] != 'R'){
					ans += r[n-1]-r[j];
					if(j + (j-i) <= n-1 && s[j+j-i] == 'R')ans--;
				}
				if(s[i] != 'B' && s[j] != 'B'){
					ans += b[n-1]-b[j];
					if(j + (j-i) <= n-1 && s[j+j-i] == 'B')ans--;
				}
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}

