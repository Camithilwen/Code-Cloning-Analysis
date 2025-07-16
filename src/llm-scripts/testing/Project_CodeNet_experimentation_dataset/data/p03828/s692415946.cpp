  /*  HARD WORK FOREVER PAYS  */
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long int ull; 
  

vector<ull> allPrimes; 
  

void sieve(int n) 
{ 

    vector<bool> prime(n+1, true); 
  

    for (int p=2; p*p<=n; p++) 
    { 

        if (prime[p] == true) 
        { 

            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  

    for (int p=2; p<=n; p++) 
        if (prime[p]) 
            allPrimes.push_back(p); 
} 

ull factorialDivisors(ull n) 
{ 
    sieve(n);  

    ull result = 1; 

    for (int i=0; i < allPrimes.size(); i++) 
    { 

        ull p = allPrimes[i]; 
        ull exp = 0; 
        while (p <= n) 
        { 
            exp = exp + (n/p); 
            p = p*allPrimes[i]; 
        } 

        result = result*(exp+1)%1000000007; 
    } 

    return result; 
} 

int main() 
{ 
	int n;
	cin>>n;
    cout << factorialDivisors(n)<<endl; 
    return 0; 
} 