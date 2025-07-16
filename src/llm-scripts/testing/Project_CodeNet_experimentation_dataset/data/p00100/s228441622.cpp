#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<ll,ll> P;
const ll MOD=10000;
const ll INF=1000000010;
const ll LINF=1000000000000000010;
const int MAX=100001;
int dx[8]={0,1,0,-1,1,-1,1,-1};
int dy[8]={1,0,-1,0,1,-1,-1,1};
int dp[310][310][610];
int main(){
    int n;
    while(cin>>n,n){
        bool f=true;
        int e[5000]={};
        for(int i=0;i<n;i++){
            ll id,p,q;
            cin>>id>>p>>q;
            e[id]+=p*q;
            if(e[id]>=1000000){
                f=false;
                cout<<id<<endl;
            }
        }
        if(f){
            cout<<"NA"<<endl;
        }
    }
	return 0;
}

