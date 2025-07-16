/**
*    author:  souzai32
*    created: 01.08.2020 23:22:01
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {   

    int n,m;
    cin >> n >> m;
    vector<tuple<int,int>> con(m);
    int s,c;
    rep(i,m){
        cin >> s >> c;
        con.at(i)=make_tuple(s,c);
    }
    sort(con.begin(),con.end());

    vector<int> num(4,-1);
    bool a=true;
    int ans=0;

    rep(i,m){
        if(num.at(get<0>(con.at(i)))!=-1 && num.at(get<0>(con.at(i)))!=get<1>(con.at(i))) a=false;
        if(get<0>(con.at(i))==1&&get<1>(con.at(i))==0&&n!=1) a=false;
        num.at(get<0>(con.at(i)))=get<1>(con.at(i));
    }

    int t=1;
    rep(i,n) t*=10;

    if(a){
        for(int i=1; i<=n; i++){
            t/=10;
            if(num.at(i)==-1){
                if(i==1 && n!=1) num.at(i)=1;
                else num.at(i)=0;
            }
            ans+=num.at(i)*t;
        }
        cout << ans << endl;
    }
    else cout << -1 << endl;

    return 0;
}