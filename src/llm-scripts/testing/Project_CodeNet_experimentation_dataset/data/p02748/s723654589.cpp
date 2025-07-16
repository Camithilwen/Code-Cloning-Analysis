#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    int a[A], b[B];
    int x[M], y[M], c[M];
    int a_min=1000000, b_min=1000000;
    rep(i,A) {
        cin >> a[i];
        if(a[i] < a_min)    a_min = a[i];
    }
    rep(i,B) {
        cin >> b[i];
        if(b[i] < b_min)    b_min = b[i];
    }
    rep(i,M) cin >> x[i] >> y[i] >> c[i];

    int res = a_min + b_min;
    int price = 0;
    
    for(int i=0; i<M; i++){
        price = a[x[i]-1] + b[y[i]-1] - c[i];
        if(price < res){
            res = price;
        }
    }
    
    cout << res << endl;
    return 0;

}