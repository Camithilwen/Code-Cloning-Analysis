/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld long double
#define   pb push_back
#define  sz(x)  (int)x.size()
#define  ff first
#define  ss second
#define  pii  pair<int,int>
using namespace std; 

vector<int> allPrimes; 
 
void sieve(int n) 
{ 
    vector<bool> prime(n+1, true); 
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) { 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
        if (prime[p]) 
            allPrimes.push_back(p); 
} 
int solve(int n) 
{ 
    sieve(n); 
    int result = 1;
    for (int  i=0; i < allPrimes.size(); i++) 
    { 
        int p = allPrimes[i]; 
        int x = 0; 
        while (p <= n) 
        { 
            x = x + (n/p); 
            p = p*allPrimes[i]; 
        } 
        result = (result*(x+1))%1000000007; 
    } 
    return result; 
}
 


signed main()
{
    int n=1; cin>>n;
    cout << solve(n) << endl ;
    return 0;
}
