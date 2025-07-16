

  /********************************************************
  **░██████╗██╗░░░░░░█████╗░██╗░░░██╗██╗░█████╗░░██████╗░**
  **██╔════╝██║░░░░░██╔══██╗██║░░░██║██║██╔══██╗██╔════╝░**
  **╚█████╗░██║░░░░░███████║╚██╗░██╔╝██║██║░░╚═╝██║░░██╗░**
  **░╚═══██╗██║░░░░░██╔══██║░╚████╔╝░██║██║░░██╗██║░░╚██╗**
  **██████╔╝███████╗██║░░██║░░╚██╔╝░░██║╚█████╔╝╚██████╔╝**
  **╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░░╚═════╝░**
  *********************************************************/

#include <bits/stdc++.h>
using namespace std;


#define ll                          long long
#define ld                          long double

#define forn(i,n)                   for(int i=0;i<n;++i)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend();
#define isSubstring(s1,s2)          s1.find(s2) != std::string::npos
	
#define pb                          push_back
#define pf                          push_front
#define mp                          make_pair
#define fr                          first
#define sc                          second

#define vpi                         <vector<pair<int,int>>
#define vi                          vector<int>
#define sz(a)                       (int)a.size()

#define   endl                       "\n"
#define     nl                       cout<<"\n";
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define MN                           INT_MIN
#define MX                           INT_MAX

bool isPrime(ll n){if(n<2)return false;for(ll x = 2;x*x <=n;x++){if(n%x == 0)return false;}return true;}
bool isPerfectSquare(long double x){long double sr=sqrt(x);return((sr-floor(sr))==0);}
int gcd(int a, int b){if(a==0)return b;if(b==0) return a;if(a==b)return a;if(a>b)return gcd(a-b,b);return gcd(a,b-a);}
int32_t main()
{
	map<string,int> m;
	m["SUN"] = 7;
	m["MON"] = 6;
	m["TUE"] = 5;
	m["WED"] = 4;
	m["THU"] = 3;
	m["FRI"] = 2;
	m["SAT"] = 1;
	string s;
	cin >> s;
	cout << m[s] << endl;
}
	