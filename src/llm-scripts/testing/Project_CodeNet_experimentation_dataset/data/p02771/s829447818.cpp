#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    string ans;

    if(a==b){
        if(a!=c){
            ans="Yes";
        }else{
            ans="No";
        }

    }else if(b==c){
        if(a!=c){
            ans="Yes";
        }else{
            ans="No";
        }
    }else if(c==a){
        if(b!=c){
            ans="Yes";
        }else{
            ans="No";
        }
    }else{
        ans="No";
    }
    cout<<ans<<endl;

    return 0;
}