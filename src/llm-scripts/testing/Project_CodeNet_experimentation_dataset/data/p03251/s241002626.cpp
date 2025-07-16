#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll a_max=-101;
    ll b_min=101;
    ll tmp;
    rep(i,n){
        cin>>tmp;
        a_max=std::max(a_max, tmp);
    }
    rep(i,m){
        cin>>tmp;
        b_min=std::min(b_min, tmp);
    }

    if(a_max<b_min && x<b_min && a_max<y){
        cout<<"No War"<<endl;
    }else{
        cout<<"War"<<endl;
    }


}

