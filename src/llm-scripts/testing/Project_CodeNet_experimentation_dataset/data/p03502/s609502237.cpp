#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b=0;
    cin>>n;
    a=n;
    while(a>0){
        b+=a%10;
        a/=10;
    }
    if(n%b==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return(0);
}