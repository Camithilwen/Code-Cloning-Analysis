#include<bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

#define debug(x) cout << '[' << #x << " is: " << x << "] " << endl;
#define imod(a , n) (a % n + n ) % n

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define inF freopen("gymnastics.in","r",stdin );
#define outF freopen("gymnastics.out" , "w" , stdout ) ;
#define sum(a)a * (a + 1 ) / 2
#define ll long long

const double eps = 1e-9 , PI = acos(-1) ;
const int N = 1e6, oo = 1e7 , M = 4 * N, mod = 1<<30 , K = 12;
int n ;

int32_t main(){

    //inF;
    // Dont Forget memset


    //calculate constraints please!!!

    fastio;
   map<int , int >mp;
   for(int  i = 0 ; i < 3 ; i++){
    int a ;
    cin >> a;
    mp[a]++;
   }
   cout << (mp.size() == 2 ? "Yes" : "No");

     return 0 ;
}

