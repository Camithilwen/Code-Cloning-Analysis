#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N = pow(10,9)+7;
    vector<ll> ans(61,0);
    ll n;
    cin >> n;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        int count=0;
        while(a!=0){
            ans.at(count) += a%2;
            a /= 2;
            count++;
        }
    }
    ll out=0;
    ll keta=1;
    for(int i=0; i<61; i++){
        //cout << "ou" << out << endl;
        //cout << "ke" << keta << endl;
        ll t = (n-ans.at(i))*ans.at(i)%N;
        out = (out+keta*t)%N;
        keta = (keta*2)%N;
        
    }
    cout << out << endl;
}
