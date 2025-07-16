#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    double a, b, c, d;
    while(cin >> a >> b >> c >> d){
        double ans = sqrt( (c-a) * (c-a) + (d-b) * (d-b));
        printf("%.6lf",ans);
    }
}