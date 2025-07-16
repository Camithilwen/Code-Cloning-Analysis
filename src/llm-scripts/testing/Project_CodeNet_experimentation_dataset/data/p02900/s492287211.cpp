#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long gcd(long a,long b){
	if (a%b==0){
		return(b);
	}
	else{
		return(gcd(b,a%b));
	}
}

long long prime_factor(long long num){
	long long bak = num;
	set<long long> nums;
	for(long long i = 2; i*i <= num; i++){
		while(bak % i == 0){
			nums.insert(i);
			bak /= i;
		}
	}
	if(bak > 1){
		nums.insert(bak);
	}
	nums.insert(1);

	return (long long) nums.size();
}

long long A, B;
int main(){
	cin >> A >> B;
	long long num = gcd(A, B);
	cout << prime_factor(num) << endl;
}