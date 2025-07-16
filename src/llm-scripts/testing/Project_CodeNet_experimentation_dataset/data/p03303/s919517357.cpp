#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int w;
    cin>>w;
    for(int i = 0;i<s.size();i++){
        if(i%w==0){
            cout<<s.at(i);
        }
    }
        
}
