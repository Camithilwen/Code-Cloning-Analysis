#include <bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define ll long long
#define llu unsigned long long
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define ABS(X) ((X)< 0 ? -(X): (X))
#define LCM(X, Y)  ( ( (X) / (GCD( (X)  , (Y) ))) * (Y) )
#define MEM( A,  B) memset((A), (B), sizeof(A))
#define MEM_VEC(V, FILL ) fill( V.begin(), V.end(), FILL)
#define FOR_EACH(IT, V) for (auto IT = V.begin(); IT != V.end(); IT++)
#define DEBUG_ARRAY_PRINT(A,I) cout<<"at pos "<< I <<"  value is: "<< A[I]
#define TURBO ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0)
const double EPS =1e-9 ;
const double PI = 3.1415926535897932384626433832795 ;
using namespace std ;
inline ll GCD(ll A, ll B){
      if ( B == 0 ) return A;
      return GCD( (B) ,  (A % B) );
}
inline ll POW(ll BASE, ll EXP) {
   ll RES = 1;
   for(ll I= 0; I < EXP; I++) RES *= BASE ;
   return RES;
}

inline ll BIGMOD  ( ll a, ll p, ll m ) {
   ll res = 1 % m;
   ll x = a % m;
   while ( p > 0 ) {
       if ( (p & 1) > 0 ) res = ( res * x ) % m;
       x = ( x * x ) % m; p >>= 1;
   }
   return res;
}
inline void FILE_HANDLE( ){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}

int main()
{

            TURBO;
            //FILE_HANDLE() ;
            string s;
            cin >> s ;
            int ans = 0 ;
            if(s[1] == 'R' && s[2] == 'R' && s[0] == 'R') ans = 3 ;
            else if(s[1] == 'R' && s[2] == 'R' ) ans = 2 ;
            else if(s[1] == 'R' && s[0] == 'R' ) ans = 2 ;
            else if(s[0] == 'R' || s[1] == 'R' || s[2] == 'R') ans = 1 ;
            cout << ans << endl ;
}

