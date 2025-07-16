#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int a,b,c;
	cin>>a>>b>>c;

	while(a!=b){
		if(a==c){
			cout<<"Yes"<<endl;
			return 0;
		}

		if(a<b) a++;
		else a--;
	}

	cout<<"No"<<endl;

	return 0;
}
