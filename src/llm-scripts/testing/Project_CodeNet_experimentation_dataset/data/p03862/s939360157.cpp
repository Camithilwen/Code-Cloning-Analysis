#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
   ll n, x;
   cin >> n >> x;
   vector<long long> candy;
   while(n--)
   {
       int a;
       cin >> a;
       candy.pb(a);
   }
   ll ans = 0;
   for(int i = 1; i < candy.size(); i++)
   {
       if(i == 1)
       {
           if(candy[i-1] > x)
           {
               ans += candy[i-1] - x;
               candy[i-1] = x;
           }
       }

       if(candy[i-1] + candy[i] > x)
       {
           ans += candy[i-1] + candy[i] - x;
           candy[i] -= candy[i-1] + candy[i] - x;
       }
   }
   cout << ans << endl;
   return 0;
}