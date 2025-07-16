#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll minus=0;
    bool allplus=false;
    ll abs_tot=0;
    ll abs_min = pow(10,9);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        if(a.at(i)==0)allplus=true;
        if(a.at(i)<0)minus++;
        abs_tot += abs(a.at(i));
        abs_min=min(abs_min, abs(a.at(i)));
    }
    if(minus%2==0) allplus=true;
    if(allplus) cout << abs_tot << endl;
    else cout << abs_tot - 2*abs_min << endl;

}
