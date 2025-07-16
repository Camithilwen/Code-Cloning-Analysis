/**
*    author:  souzai32
*    created: 12.08.2020 23:03:31
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    int a=(n+1)/2,b=n/2;
    vector<int> v(n),o(a),e(b);
    rep(i,n) cin >> v.at(i);
    rep(i,a) o.at(i)=v.at(2*i);
    rep(i,b) e.at(i)=v.at(2*i+1);

    // rep(i,a) cout << o.at(i) << endl;
    // rep(i,b) cout << e.at(i) << endl;

    sort(o.begin(),o.end());
    sort(e.begin(),e.end());

    int count=1;
    int on,en,co1=0,co2=0,ce1=0,ce2=0;

    rep(i,a){
        if(i==0) continue;
        else if(o.at(i)==o.at(i-1)) count++;
        else if(o.at(i)!=o.at(i-1)){
            if(count>=co1){
                co2=co1;
                co1=count;
                on=o.at(i-1);
            }
            else if(count>=co2){
                co2=count;
            }
            count=1;
        }
        if(i==a-1){
            if(count>=co1){
                co2=co1;
                co1=count;
                on=o.at(i);
            }
            else if(count>=co2){
                co2=count;
            }
            count=1;
        }
    }
    rep(i,b){
        if(i==0) continue;
        else if(e.at(i)==e.at(i-1)) count++;
        else if(e.at(i)!=e.at(i-1)){
            if(count>=ce1){
                ce2=ce1;
                ce1=count;
                en=e.at(i-1);
            }
            else if(count>=ce2){
                ce2=count;
            }
            count=1;
        }
        if(i==b-1){
            if(count>=ce1){
                ce2=ce1;
                ce1=count;
                en=e.at(i);
            }
            else if(count>=ce2){
                ce2=count;
            }
            count=1;
        }
    }

    int ans;
    if(on==en) ans=min(n-ce1-co2,n-co1-ce2);
    else ans=n-ce1-co1;

    // cout << co1 << ' ' << co2 << ' ' << ce1 << ' ' << ce2 << endl;
    cout << ans << endl;

    return 0;
}