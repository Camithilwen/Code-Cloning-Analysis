#include<stdio.h>
#define ll long long

int main()
{
	ll n, j = 0;
	char str[255];
	
	scanf("%lld", &n);
	
	while(n != 0){
		--n;
		str[j++] = n % 26 + 'a';
		n /= 26;
	}
	for(int i = j - 1; i >= 0; i--){
		printf("%c", str[i]);
	}
}