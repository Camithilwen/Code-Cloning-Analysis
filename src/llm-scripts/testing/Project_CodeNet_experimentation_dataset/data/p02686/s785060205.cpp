#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
typedef long long ll;
using namespace std;

const int N = 1000001;

bool cmp(const pair<int,int>&a, const pair<int,int>&b){
    return a.S > b.S;
}

int n;
vector<pair<int,int>>v1, v2;

int main(){
    IOS

    int n;
    cin >> n;
    FOR(i,1,n){
        string s;
        cin >> s;
        int m = s.length();
        int open = 0, closed = 0;
        FOR(j,0,m-1){
            if(s[j] == '(')
                open++;
            else{
                if(open > 0)
                    open--;
                else
                    closed++;
            }
        }
        if(open > closed)
            v1.pb(mp(open, closed));
        else
            v2.pb(mp(open, closed));
    }
    int remmatch = 0;

    sort(all(v1), cmp);
    sort(all(v2));

    for(auto p:v2){
        if(p.F > remmatch){
            cout << "No";
            return 0;
        }
        remmatch -= p.F;
        remmatch += p.S;
    }
    for(auto p:v1){
        if(p.F > remmatch){
            cout << "No";
            return 0;
        }
        remmatch -= p.F;
        remmatch += p.S;
    }

    if(remmatch != 0)
        cout << "No";
    else
        cout << "Yes";


    return 0;
}