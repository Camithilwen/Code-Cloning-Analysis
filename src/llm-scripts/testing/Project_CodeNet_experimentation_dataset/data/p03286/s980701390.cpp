#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> mod(int a, int b){
    int d = a/b;
    int r = a%b;
    if(r<0){
        d++;
        r = a-(d*b);
    }


    return make_pair(d, r);
}
int main(){
    int32_t n;
    int bits[32] = {0};
    scanf("%d", &n);
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    int i=32;
    while(n != 0){
        pair<int, int> div = mod(n, -2);
        n = div.first;
        bits[--i] = div.second;
    }

    int prnt = false;
    for(int i=0; i<32; i++){
        if(!prnt && bits[i]) prnt = true;
        if(prnt) cout << bits[i];
    }
    cout << endl;






}
