#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        if(s.length()==2){

        }else if(s.length()==3){
            reverse(s.begin(),s.end());
        }
        cout<<s<<endl;
    }
    
}