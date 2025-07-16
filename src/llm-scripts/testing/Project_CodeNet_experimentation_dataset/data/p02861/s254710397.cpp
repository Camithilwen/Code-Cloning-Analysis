#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

double len(int x1,int x2, int y1,int y2){
    double res;
    double x=x1-x2;
    double y=y1-y2;
    res=pow(x*x+y*y,0.5);
    return res;
}

int main(){
    int n;
    cin>>n;
    int x[n],y[n];
    double ans=0;
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans+=len(x[i],x[j],y[i],y[j])*2.0/n;
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}