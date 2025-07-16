#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

double kaijyo(int n){
    int k(1);
    for(int i=n;i>0;i--){
        k *= i;
    }

    return k;
}

double distance(int x[],int y[],int i,int j){
    int dx = (x[i] - x[j]) * (x[i] - x[j]);
    int dy = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(dx+dy);
}

int main(){
    int x,y;
    cin >> x >> y;

    int ans(0);
    switch (x)
    {
    case 1:
        ans += 300000;
        break;
    case 2:
        ans += 200000;
        break;
    case 3:
        ans += 100000;
        break;

    default:
        break;
    }
    switch (y)
    {
    case 1:
        ans += 300000;
        break;
    case 2:
        ans += 200000;
        break;
    case 3:
        ans += 100000;
        break;

    default:
        break;
    }

    if(x==1 && y==1)    ans += 400000;

    cout << ans << endl;

    return 0;
}