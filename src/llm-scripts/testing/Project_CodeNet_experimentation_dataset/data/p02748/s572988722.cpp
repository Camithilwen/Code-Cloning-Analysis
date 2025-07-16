#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi = vector<int>;
using vl= vector<ll>;
using vs=vector<string>;

ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a);}
ll max(ll a, ll b) {if (a > b) return a; else return b;}
ll min(ll a, ll b) {if (a < b) return a; else return b;}
ll power(ll a,ll b) {long long res = 1; while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;} return res;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    
    for(int p=0;p<testcase;p++){
        ll a=0,b=0,m=0;
        cin>>a>>b>>m;
        ll array[a]={0};
        ll array2[b]={0};
        ll array3[m]={0};
        ll mina=9999999999,minb=9999999999;
        for(int i=0;i<a;i++){
            cin>>array[i];
            mina=min(array[i],mina);
        }
        for(int i=0;i<b;i++){
            cin>>array2[i];
            minb=min(array2[i],minb);
        }
        ll min1=9999999999; 
        ll min_index=0;
        for(int i=0;i<m;i++){
            ll tempa=0,tempb=0,tempc=0;
            cin>>tempa>>tempb>>tempc;
            array3[i]=array[tempa-1]+array2[tempb-1]-tempc;
            if(array3[i]<=min1)
            min1=array3[i];
        }
        min1=min(min1,mina+minb);
        

        cout<<min1;
        
        
        
        
        
        
        
        }

    return 0;
}
