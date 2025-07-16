#include<stdio.h>
#define ll long long

int main(){
	ll n, rev, i = 0;
	scanf("%lld", &n);
	char str[100];
	while(n){
		if(n == 0){
			break;
		}
		n--;
		rev = n % 26;
		n /= 26;
		str[i] = 'a' + rev;
		i++;
	}
	for(ll j = i - 1; j >= 0; j--){
		printf("%c", str[j]);
	}
	puts("");
	return 0;
}