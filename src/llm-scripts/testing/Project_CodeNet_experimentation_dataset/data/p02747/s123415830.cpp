#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    string ans="Yes";
    for(int i=0;i<s.size();i+=2){
        if(s.size()%2==1){
            ans="No";
            break;
        }
        if(s.at(i)!='h' || s.at(i+1)!='i'){
            ans="No";
            break;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
