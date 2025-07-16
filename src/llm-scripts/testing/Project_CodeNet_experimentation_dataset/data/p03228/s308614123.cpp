#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	ll a,b;
	int k;

	cin >> a >> b >> k;

	for(int i=0;i<k;i++){
		if(i%2==0){
			a -= a%2;
			b += a/2;
			a -= a/2;
		}else{
			b -= b%2;
			a += b/2;
			b -= b/2;
		}
	}

	cout << a << " " << b << endl;

	return 0;
}
