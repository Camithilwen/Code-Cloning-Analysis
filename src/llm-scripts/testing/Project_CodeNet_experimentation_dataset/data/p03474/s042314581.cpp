#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a,b;
string s;
int main(void){
    cin>>a>>b>>s;
    for(int i=0;i<a+b+1;i++){
        if(i==a){
            if(s[i]!='-'){
                cout<<"No"<<endl;
                return 0;
            }
        }else{
            if(s[i]=='-'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    
}
