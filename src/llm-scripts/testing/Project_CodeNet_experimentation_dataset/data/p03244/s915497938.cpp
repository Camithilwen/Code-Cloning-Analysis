#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n;cin >> n;
    n /= 2;
    vector<int> e(100001),o(100001);
    for(int i = 0; i < n*2; i++) {
        int v;cin >> v;
        if(i%2==0){
            o[v]++;
        }
        else e[v]++;
    }

    int a=0,b=0,c=0,d=0;
    for(int i = 0; i < 100001; i++) {
        if(e[i]>a){
            c=i;
            a=e[i];
        }
    }
    for(int i = 0; i < 100001; i++) {
        if(o[i]>b){
            d=i;
            b=o[i];
        }
    }

    int x=a+b;
    if(c==d){
        sort(e.begin(),e.end());
        sort(o.begin(),o.end());
        x=max(a+o[99999],b+e[99999]);
    }
    cout << n*2-x << endl;

    return 0;
}