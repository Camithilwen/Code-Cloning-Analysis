#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define mapa map<char,int>
#define repa(p,A) for(auto p:A)
#define pb push_back
/*#define sort(a) sort(a.begin(),a.end())*/
#define reverse(a) reverse(a.begin(),a.end())
const double PI=acos(-1);
using namespace std;

int main( ) {
    vec A,B;
    ll N;
    cin>>N;
    rep(i,0,N) {
        ll a;
        cin>>a;
        if(i%2==0) {
            A.push_back(a);   
        }
        else {
            B.push_back(a);
        }
        }
        map<ll,ll> C,D;
        rep(i,0,A.size()) {
            C[A[i]]++;
        }
        rep(i,0,B.size()) {
            D[B[i]]++;
        }
        vector<pair<ll,ll>> E,F;
        for(auto p:C) {
            E.push_back(pair<ll,ll>(p.first,p.second));
            }
        for(auto p:D) {
            F.push_back(pair<ll,ll>(p.first,p.second));
            }
        auto comp = [](pair<int, int> a, pair<int, int> b) {
        return a.second>b.second;
    };   
        ll count=0;
        sort(E.begin(),E.end(),comp);
        sort(F.begin(),F.end(),comp);
        if(E[0].first==F[0].first) {
            if(E.size()>=2) {
                count+=E[0].second+max(E[1].second,F[1].second);
                }
            else count+=E[0].second;    
        }

        else count+=E[0].second+F[0].second;

        cout<<N-count<<endl;















        }
        

