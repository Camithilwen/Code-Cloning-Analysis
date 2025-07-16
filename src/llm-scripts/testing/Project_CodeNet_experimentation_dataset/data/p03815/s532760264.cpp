#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    ll x;
    cin>>x;
    ll d=x/11;
    ll r=x%11;
    if(0==r){
        cout<<2*d<<endl;
    }else{
        if(r<7){
            cout<<2*d+1ll<<endl;
        }else{
            cout<<2*d+2ll<<endl;
        }
    }
    return 0;
}