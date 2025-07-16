#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll x,y;cin>>x>>y;
    
    ll ans=0;

    if(x==y){cout<<0<<endl;return 0;}//ｘ yが一致する場合

    if(x==0){//x==0の場合
        if(y>0){
            cout<<y<<endl;
            return 0;
        }else{
            cout<<abs(y)+1<<endl;
            return 0;
        }
    }

    if(y==0){//y==0の場合
        if(x>0){
            cout<<x+1<<endl;
            return 0;
        }else{
            cout<<abs(x)<<endl;
            return 0;
        }
    }

    if(x>=0 && y>=0){//x yの正負で場合わけ
        if(abs(y)>=abs(x)){
            ans=abs(y)-abs(x);
        }else{
            ans=abs(x)-abs(y)+2;
        }
    }else if(x>=0 && y<0){
        if(abs(y)>=abs(x)){
            ans=abs(y)-abs(x)+1;
        }else{
            ans=abs(x)-abs(y)+1;
        }
    }else if(x<0 && y>=0){
        if(abs(y)>=abs(x)){
            ans=abs(y)-abs(x)+1;
        }else{
            ans=abs(x)-abs(y)+1;
        }
    }else if(x<0 && y<0){
        if(abs(y)>=abs(x)){
            ans=abs(y)-abs(x)+2;
        }else{
            ans=abs(x)-abs(y);
        }
    }

    cout<<ans<<endl;

    return 0;
}