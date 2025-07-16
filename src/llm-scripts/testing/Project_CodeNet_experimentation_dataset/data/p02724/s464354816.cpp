#include<bits/stdc++.h>
#define mp make_pair
#define endl "\n"
#define v vector
#define b begin()
#define e end()
using namespace std;
typedef long long ll;
typedef long l;
typedef long long unsigned ull;

int main(){

    /*int t;
    while(t--){

    }*/
    ll n;
    cin>>n;
    ll m = n/500;
    ll q = m*1000;
    n -= (m*500);
    ll p = (n/5)*5;
    cout<<q+p;

    return 0;

}