#include<bits/stdc++.h>
using namespace std;

int main(){
    double n,m,d,l;cin>>n>>m>>d;
    l=2*(n-d);
    if(d==0)l/=2;
    cout<<fixed<<setprecision(15)<<l*(m-1)/n/n<<endl;
}