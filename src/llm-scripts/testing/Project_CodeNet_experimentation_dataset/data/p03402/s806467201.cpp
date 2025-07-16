#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;

void ptn(vector<vector<bool>> &ans,ll i,ll j,ll p){
    if(p==1){
        ans[i*4][j*4]=1;ans[i*4+1][j*4]=1;ans[i*4+2][j*4]=1;
        ans[i*4][j*4+1]=1;ans[i*4+2][j*4+1]=1;
        ans[i*4][j*4+2]=1;ans[i*4+1][j*4+2]=1;ans[i*4+2][j*4+2]=1;
    }
    if(p==2){
        ans[i*4+1][j*4+1]=1;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll A,B;
    cin>>A>>B;
    
    bool bo=(A>B);
    if(bo){
        ll tmp=A;
        A=B;
        B=tmp;
    }
    
    vector<vector<bool>> ans(100,vector<bool>(100,0));
    
    if(A<=B){
        ll count=0;
        for(ll i=0;i<100;i++){
            for(ll j=0;j<100;j++){
                ptn(ans,i,j,3);
            }
        }
        for(ll i=0;i<A-1;i++){
            ptn(ans,count/25,count%25,1);
            count++;
        }
        for(ll i=0;i<B-A+1;i++){
            ptn(ans,count/25,count%25,2);
            count++;
        }
    }
    
    printf("100 100\n");
    for(ll i=0;i<100;i++){
        for(ll j=0;j<100;j++){
            if((ans[i][j]==1 && !bo) || (ans[i][j]==0 && bo)) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    
    return 0;
}
