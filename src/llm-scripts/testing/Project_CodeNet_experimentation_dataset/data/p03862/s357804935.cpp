#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    ll cnt=0;
    if(a.at(0)>x){
        cnt+=a.at(0)-x;
        a.at(0)=x;
    }
    for(int i=1; i<n; i++){
        ll k=a.at(i)+a.at(i-1);
        if(k>x){
            cnt+=k-x;
            a.at(i) -= k-x;
        }
    }
    cout << cnt << endl;
}