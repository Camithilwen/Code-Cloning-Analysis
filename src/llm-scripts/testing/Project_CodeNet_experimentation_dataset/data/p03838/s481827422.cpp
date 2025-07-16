/**
*    author:  souzai32
*    created: 02.08.2020 15:41:51
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    long long int x,y;
    cin >> x >> y;

    long long int count=0;
    while(1){
        if(x==y) break;

        else if(x<y){
            if(abs(x)<abs(y)) {
                if(x>=0){
                    count+=y-x;
                    x+=y-x;
                }
                else{
                    count++;
                    x*=-1;
                }
            }
            else if(abs(x)==abs(y)){
                count++;
                x*=-1;
            }
            else{
                if(y>=0){
                    count+=abs(x)-y;
                    x+=abs(x)-y;
                }
                else{
                    count+=y-x;
                    x+=y-x;
                }
            }
        }
        else if(y<x){
            if(abs(x)>abs(y) || x<0){
                count++;
                x*=-1;
            }
            else if(abs(x)==abs(y)){
                count++;
                x*=-1;
            }
            else{
                count+=abs(y)-x;
                x+=abs(y)-x;
            }
        }
        //cout << x << ' ' << y << endl;
    }
    cout << count << endl;

    return 0;
}