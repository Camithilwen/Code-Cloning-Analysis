#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    int sum=0;
    rep(i,n-1){
        sum+=abs(p[i]-p[i+1]);
    }
    sum+=abs(p[0]); sum+=abs(p[n-1]);
    if(p[0]*(p[1]-p[0])>=0){
        cout<<sum<<endl;
    }else{
        cout<<sum-2*min(abs(p[0]), abs(p[1]-p[0]))<<endl;
    }
    for(int i=1; i<n-1; ++i){
        if((p[i-1]-p[i])*(p[i]-p[i+1])>=0){
            cout<<sum<<endl;
        }else{
            cout<<sum-2*min(abs(p[i-1]-p[i]), abs(p[i]-p[i+1]))<<endl;
        }
    }
    if((p[n-2]-p[n-1])*p[n-1]>=0){
        cout<<sum<<endl;
    }else{
        cout<<sum-2*min(abs(p[n-2]-p[n-1]), abs(p[n-1]))<<endl;
    }
    return 0;
}