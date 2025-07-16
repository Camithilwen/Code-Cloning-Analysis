#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    if((a<=c&&c<=b)||(b<=c&&c<=a)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
}
