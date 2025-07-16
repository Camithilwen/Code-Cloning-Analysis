#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y; cin >> x >> y;
    int ans = 0;
    if(x>0){
        if(y>0){
            if(x>y){
                ans++; // x -> -x
                ans += abs(x-y); // x -> -y
                ans++; // x-> y
            }else if(x < y){
                ans+= y-x; // x->y
            }
        }else if(y<0){
            if(abs(x) > abs(y)){
                ans++; // x->-x
                ans+= abs(x) - abs(y); // x->-y
            }else if(abs(x) < abs(y)){
                ans+= abs(y) - abs(x); // x->y
                ans++;   // x -> -y
            }else{
                ans++;
            }
        }else{
            ans++;
            ans+= x;
        }
    }else if(x<0){
        if(y>0){
            if(abs(x)>abs(y)){
                ans += abs(x) -abs(y);
                ans++;
            }else if(abs(x)<abs(y)){
                ans++;
                ans += abs(y) - abs(x);
            }else{
                ans++;
            }
        }else if(y<0){
            if(abs(x)>abs(y)){
                ans += abs(x) -abs(y);
            }else if(abs(x)<abs(y)){
                ans++;
                ans += abs(y) - abs(x);
                ans++;
            }
        }else{
            ans+=abs(x);
        }
    }else{
        if(y>0) ans+=y;
        else if(y<0) ans+= abs(y) + 1;
    }
    cout << ans << endl;
    return 0;
}