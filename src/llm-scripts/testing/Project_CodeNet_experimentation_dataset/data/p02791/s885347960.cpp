/*
   Push yourself, because no one else is going to do it for you.
*/
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long int
#define PI 2 * acos(0.0)
#define MAX 10000000000000000
#define in(a) scanf("%d",&a);
#define out(a) printf("%d",a);
#define INF 1000000 
#define M 1000000007
using namespace std;
int main(){ 
   fast_io
   ll n;
   cin>>n;
   ll a[n];
   for(ll i = 0;i<n;i++) cin>>a[i];
   ll ans = a[0];
   ll sum = 1;
   for(ll i = 1;i<n;i++){
       if(ans > a[i]){
            sum++;
       }
       ans = min(a[i],ans);
   }
   cout<<sum<<endl;
   return 0; 
}  