#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> v;
    for(int i = 0; i < n; i++){
        auto itr = lower_bound(v.begin(), v.end(), a[i]);
        if(i == 0){
            v.push_back(a[i]);
        }else{
            int p = distance(v.begin(), itr);
            if(p == 0){
                v.insert(v.begin(), a[i]);
            }else{
                p--;
                v[p] = a[i];
            }
        }
    }


    cout << v.size() << endl;
}