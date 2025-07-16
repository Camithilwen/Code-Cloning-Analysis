#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    if(a[0]!=0){
        cout<<-1<<endl;
        return 0;
    }
    ll res=0;
    reverse(a.begin(),a.end());
    ll maxi=0;
    rep(i,n){
        if(a[i]<maxi){
            cout<<-1<<endl;
            return 0;
        }
        if(chmax(maxi,a[i]))res+=a[i];
        maxi--;
    }
    cout<<res<<endl;
}