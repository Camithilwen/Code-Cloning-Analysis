#include <bits/stdc++.h>
typedef long long ll;
int const N = 1e6+5;
int const mod = 1e9+7;
using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll counter=0;
void prime_fuct(ll x){
    for (ll i = 2; i * i <= x; i++){
        if(x%i==0){
            while (x % i == 0){
                x /= i;
            }
            counter++;
        }
    }
    if(x != 1){
            counter++;
    }
    cout<<counter+1;
}

void solve(){
	ll a,b;
    cin>>a>>b;
    prime_fuct(gcd(a,b));
}

int main()
{
  int t;
	t=1;
     while(t--)
    {

		solve();

    }
	return 0;
}
