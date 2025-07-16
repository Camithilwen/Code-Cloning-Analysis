#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    int n;
    while(cin >> n){
        range(i,1,n+1){
            int x = i;
            if(x % 3 == 0) cout << " " << x;
            else{
                while(x){
                    if(x % 10 == 3){
                         cout << " " << i;
                         break;
                    }
                    x /= 10;
                }
            }
        }
        cout << endl;
    }
}