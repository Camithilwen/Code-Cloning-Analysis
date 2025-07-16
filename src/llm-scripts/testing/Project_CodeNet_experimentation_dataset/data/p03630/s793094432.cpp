#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

string S[2009];
int H,W,ans;
int hig[2009];

bool ck(int i,int j){
    return (1^(S[i][j]==S[i][j-1])^(S[i-1][j]==S[i-1][j-1]));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>H>>W;
    rep(i,H) cin>>S[i];
    
    ans=max(H,W);
    FOR(i,1,H){
        stack<pii> stc;
        stc.push({0,0});
        FOR(j,1,W){
            if(ck(i,j)) hig[j]++;
            else hig[j]=0;
            int h=stc.top().first;
            int w=stc.top().second;
            int ww=0;
            while(h>hig[j]){
                ww+=w;
                chmax(ans,(h+1)*(ww+1));
                stc.pop();
                h=stc.top().first;
                w=stc.top().second;
            }
            if(h<hig[j]){
                stc.push({hig[j],1+ww});
            }else{
                stc.top().second+=1+ww;
            }
        }
        int ww=0;
        while(!stc.empty()){
            int h=stc.top().first;
            int w=stc.top().second;
            ww+=w;
            chmax(ans,(h+1)*(ww+1));
            stc.pop();
        }
    }
    cout1(ans)
}