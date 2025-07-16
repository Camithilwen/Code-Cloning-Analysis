#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	int mn = 2019;
	if(b-a+1>=2019) cout<<0;
	else{
		for(int i=a; i<=b; i++){
			for(int j=i+1; j<=b; j++){
				mn = min(mn,( (i%2019)*(j%2019) )%2019);
			}
		}
		cout<<mn;
	}
}