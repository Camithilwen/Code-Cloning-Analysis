#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b;
	cin>>a>>b;
	long long int ans=max(a,b);
	if(a>=b){
		a--;
		if(a>0&&a>=b){
			cout<<ans+a;
		}
		else{
			cout<<ans+b;
		}
	}
	else{
		b--;
		if(b>0&&b>=a){
			cout<<ans+b;
		}
		else{
			cout<<ans+a;
		}
	}
	return 0;
}