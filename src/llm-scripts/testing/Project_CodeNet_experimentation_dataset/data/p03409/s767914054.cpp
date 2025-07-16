#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a,b;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(y,x));
    }
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        b.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    rep(i,0,n){
        int x,y;
        x=a.at(i).second;
        y=a.at(i).first;
        a.at(i)=make_pair(x,y);
    }

    int numPair=0;
    rep(i,0,n){ //blue
        _rep(j,n-1,0){ //red
            if(a.at(j).first<b.at(i).first && a.at(j).second<b.at(i).second){
                numPair++;
                a.at(j)=make_pair(2*n,2*n);
                break;
            }
        }
    }

    cout<<numPair<<endl;
}