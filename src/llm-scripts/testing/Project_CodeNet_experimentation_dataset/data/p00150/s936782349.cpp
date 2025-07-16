#include <iostream>
#include <cmath>
using namespace std;

int dummy_prime(int n,int i){return i>1 ? n%i ? dummy_prime(n,i-1) : 0 : 1;}
int isprime(int n){return n>1 ? dummy_prime(n,(int)sqrt(n)) : 0;} 

int main(){
	int n;
	while(cin >> n && n){
		while(n>4){
			if(isprime(n) && isprime(n-2)){
				cout << n-2 << " " << n << endl;
				break;
			}
			n--;
		}
	}
}