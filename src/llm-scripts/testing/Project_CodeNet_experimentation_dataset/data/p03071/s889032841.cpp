#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	int d = 2;
	int sum = 0;
	while(d--){
		if(a>b){
			sum+=a;
			a=a-1;
		}
		else if(a<b){
			sum+=b;
			b=b-1;
		}
		else if(a==b && d==2){
			sum = a+b;
		}
		else{
			sum+=a;
		}
	}
	cout << sum << endl;
	return 0;
}
