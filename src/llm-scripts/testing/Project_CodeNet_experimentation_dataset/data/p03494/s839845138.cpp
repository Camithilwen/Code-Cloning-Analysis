#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 1e5+10, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
int a ;
int main()
{
    Tsetso ;
    int n  , mn = 1e9 ;
    cin >> n ;
    for ( int i = 0 ; i  <n ; i++)
    {
        int cnt = 0 ;
        cin >> a ;
        while (a%2 == 0)
                a /= 2 , cnt++ ;
        mn = min(cnt,mn) ;
    }
    cout << mn ;
}
