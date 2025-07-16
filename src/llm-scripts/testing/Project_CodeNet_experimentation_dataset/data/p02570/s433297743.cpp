/*Author- Soumak Poddar*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define sll signed long long int
#define ull unsigned long long int
#define um unordered_map
#define us unordered_set
#define mm multimap
#define mp make_pair
#define pb push_back
#define M 1000000007

bool comp(pair<int,int> a,pair<int,int> b)
{
   return a.second<b.second;
}

template<typename T>
T gcd(T a,T b)
{
   if(a==0)
      return b;
   return gcd(b%a,a);
}
template<typename T>
T lcm(T a,T b)
{
   T g=gcd<T>(a,b);
   return (a*b)/g;
}
template<typename T>
bool isprime(T n)
{
   if(n<=1)
      return false;
   for(int i=2;i<sqrt(n);i++)
      if(n%i==0)
         return false;
   return true;
}

void solve();
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("error.txt", "w", stderr);
      freopen("output.txt", "w", stdout);
   #endif
   
   int t=1;
   // cin>>t;
   while(t--)
   {
      solve();
      cout<<"\n";
   }
   cerr<<"Time Taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}
void solve()
{
   int d,t,s;
   cin>>d>>t>>s;
   double at=(double)d/s;
   if(at<=t)
      cout<<"Yes";
   else
      cout<<"No";
}