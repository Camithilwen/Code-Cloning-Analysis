#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i, n) for( int i=0 ; i<n ; i++ )
#define f(i, a, b) for( int i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
ll fact(ll n)
{
    ll ans = 1e14;
    for(ll i = 1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ll sol = (i - 1) + (n/i - 1);
            ans = min(ans,sol);
        }
    }
    return ans;
}
int visited[200000] = {0};
vector<vector<int> > v(200000);
int dfs(int x)
{
    int ans = 0;
    if(visited[x]==0)
    {
        visited[x] = 1;
        ans++;
        int a = v[x].size();
        for(int j = 0; j<a; j++)
        {
            int data = v[x][j];
            ans = ans + dfs(data);
        }
    }
    return ans;
}
void primefactors(int n)
{
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";

}
double fib(int n)
{
    double sol1,sol2;
    sol1 = (1 + sqrt(5))/2;
    sol2 = (1 - sqrt(5))/2;
    sol1 = pow(sol1,n);
    sol2 = pow(sol2,n);
    double ans = sol1 - sol2;
    ans = ans/sqrt(5);
    //ans = int(ans);
    return ans;
}

ll digits(ll n)
{
    return floor(log10(double(n))) + 1;
}


int main()
{

    string s,t;
    cin>>s>>t;
    cout<<t + s;
}
