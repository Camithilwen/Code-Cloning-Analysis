#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> ti;
ll mod=1E9+7;
 
#define REP(a,b,c) for(ll a=b;a<(c);a++)
#define PER(a,b,c) for(ll a=b;a>=(c);a--)

ll ii(){ ll x; cin >> x; return x; }
string is(){ string x; cin >> x; return x; }
ld id(){ ld x; cin >> x; return x; }
void oi(ll x){ cout << x; }
void od(ld x){ cout << fixed << setprecision(10) << x; }
void os(string x){ cout << x; }
void oe(){ cout << endl; }
void oie(ll x){ oi(x); oe(); }
void ode(ld x){ od(x); oe(); }
void ose(string x){ os(x); oe(); }

int main(){
    ll N=ii();
    ll M=ii();

    ll r=((N-1)/2);
    ll r3=r/2;
    ll r2=r-r3;

    REP(i,0,min(r2,M)){
        oi(i+1);
        os(" ");
        oie(2*r2-i);
    }

    REP(i,0,min(r3,M-r2)){
        oi(2*r2+i+1);
        os(" ");
        oie(2*(r2+r3)+1-i);
    }

    return 0;
}
