#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
constexpr double pi=3.1415926535897932;
int main(){
    int n;
    cin >> n;
    vector<double> x(n),y(n);
    loop(i,n)cin >> x[i] >> y[i];
    loop(i,n){
        vector<double> theta;
        loop(j,n){
            if(i==j)continue;
            theta.push_back(atan2(y[i]-y[j],x[i]-x[j]));
        }
        sort(theta.begin(),theta.end());
        double probability=0;
        if(theta[n-2]-theta[0]<pi)probability=0.5-(theta[n-2]-theta[0])/(2*pi);
        else{
            loop(i,n-2){
                if(theta[i+1]-theta[i]>pi){
                    probability=-0.5+(theta[i+1]-theta[i])/(2*pi);
                    break;
                }
            }
        }
        cout << setprecision(20) << probability << endl;
    }
    return 0;
}