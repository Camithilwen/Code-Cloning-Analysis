#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int x,y;
    ll cnt=0;
    cin >> x >> y;
    if(x>=0 && y>=0){
        if(x>y){
            x=0-x;
            ++cnt;
            while(1){
                if(abs(x)==abs(y)) break;
                ++x; ++cnt;
            }
            if(y!=0) ++cnt;
        }else{
            while(1){
                if(x==y) break;
                ++x; ++cnt;
            }
        }
    }else if(x<0 && y<0){
        if(abs(x)>=abs(y)){
            while(1){
                if(x==y) break;
                ++x; ++cnt;
            }
        }else{
            x=0-x;
            ++cnt;
            while(1){
                if(abs(x)==abs(y)) break;
                ++x; ++cnt;
            }
            ++cnt;
        }
    }else if(x<0 && y>=0){
        if(abs(x)<=abs(y)){
            x=0-x;
            ++cnt;
        }
        while(1){
            if(abs(x)==abs(y)) break;
            ++x; ++cnt;
        }
        if(x!=y) ++cnt;
    }else if(x>=0 && y<0){
        if(abs(x)<abs(y)){
            while(1){
                if(abs(x)==abs(y)) break;
                ++x; ++cnt;
            }
            ++cnt;
        }else{
            x=0-x;
            ++cnt;
            while(1){
                if(x==y) break;
                ++x; ++cnt;
            }    
        }
    }
    cout << cnt << "\n";
    return 0;
}   