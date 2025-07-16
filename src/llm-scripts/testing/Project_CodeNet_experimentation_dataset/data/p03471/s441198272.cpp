#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< ll, ll >   cp2;
typedef pair< string, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789


///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int N;
ll Y;
bool ans = false;
ll A, B, C;

int main(){
    
    cin>>N>>Y;
    
    REP( i, N+1 ){
        REP( j, N+1-i ){
            A = i;
            B = j;
            C = N-i-j;
            if( A*1000+B*5000+C*10000 == Y ){
                ans = true;
                i = N;
                break;
            }
        }
    }
    
    if( ans ){
        printf("%lld %lld %lld\n", C, B, A);
    }
    else{
        puts("-1 -1 -1");
    }
    
    return 0;
}
