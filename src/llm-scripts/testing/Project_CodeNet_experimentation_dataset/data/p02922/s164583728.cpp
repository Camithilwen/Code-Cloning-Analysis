#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int required = 1,extended = a;
    while(extended < b){
        required++;
        extended += a-1;
    }
    if(b == 1){
        cout<<0;
    }else{
        cout<<required;
    }
    return 0;
}