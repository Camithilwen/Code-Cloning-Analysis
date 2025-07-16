
    #include <bits/stdc++.h>
    #define rep(i,a,b) for(int i=(a);i<(b);i++)
    #define per(i,a,b) for(int i=(a);i>(b);i--)
    typedef long long ll;
    using namespace std;

    typedef double dd;

    int main(){
         ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,t;
    cin>>n>>x>>t;
    if((n%x)!=0) cout<<t*((n/x)+1);
    else {cout<<t*((n/x));return 0;}



        return 0;
    }
