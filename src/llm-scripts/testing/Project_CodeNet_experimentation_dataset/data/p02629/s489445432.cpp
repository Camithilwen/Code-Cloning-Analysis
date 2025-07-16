#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;



int main(void){
    ll n;
    cin >> n;
    char c[26+1]="abcdefghijklmnopqrstuvwxyz";
    vector<char> v;
    while(n){
        v.push_back(c[(--n)%26]);
        n/=26;
    }
    RREP(i,(int)v.size()-1)
        cout << v[i];
    cout << endl;
    return 0;
}