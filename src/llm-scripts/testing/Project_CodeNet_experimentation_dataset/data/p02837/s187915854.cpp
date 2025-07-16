#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using pint = pair<int,int>;
using vpil = vector<pint>;
using vppil = vector<vpil>;

int main(){
    int n;
    cin >> n;
    vppil l(n);
    rep(i,n){
        int a;
        cin>>a;
        rep(j,a){
            pint xy;
            cin>>xy.first>>xy.second;
            xy.first--;
            l.at(i).push_back(xy);
        }
    }
    //end input
    //binary search
    int ans=0;
    rep(bit,1<<n){
        bool flag=true;
        rep(i,n){
            if(bit&(1<<i)){//is bit true
                //get items from l;
                for(pint xy:l.at(i)){
                    if((bit&(1<<xy.first))>>xy.first!=xy.second){
                        flag=false;
                        i+=n;
                        break;//=>gotonext
                    }
                }
            }
        }
        //gotonext
        if(flag){ans=max(__builtin_popcount(bit),ans);}
    }
    cout<<ans<<endl;
}