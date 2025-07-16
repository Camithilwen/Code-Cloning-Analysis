#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string.h>
#include <cmath>
#include <queue>
#include <string>
#include <stack>
#include <utility>
#include <queue>
#include <cmath>
#define mp make_pair
#define pii pair<int,int> 
#define ff first
#define ss second
#define ll long long 
#define vi vector<int>

using namespace std;

ll _sieve_size; 
bitset<10000010> bs; 
vi primes; 
void sieve(ll upperbound) { 
_sieve_size = upperbound + 1; 
bs.set(); 
bs[0] = bs[1] = 0; 
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i);
} } 
bool isPrime(ll N) { 
if (N <= _sieve_size) return bs[N]; 
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; 
} 

int a;

int main()
{
	sieve(11000);
	while(1)
	{	
		scanf("%d",&a);
		if(a==0)break;
		if(a%2==0)
		a-=3;
		else
		a-=2;
		//printf("%d",b);
		while(1)
		{
			if(isPrime(a)&&isPrime(a+2))
			{
				printf("%d %d\n",a,a+2);
				break;
			}
			a-=2;
		}
	}
}