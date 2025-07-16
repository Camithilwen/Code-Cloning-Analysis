#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>vec(n);
    int s;
    string c;
    rep(i,m){
       cin>>s>>c;
       if(n!=1&&s==1&&c=="0"){
            cout<<-1<<endl;
             return 0;
        }
        if(vec.at(s-1)==""){
           vec.at(s-1)=c;
        }else if(vec.at(s-1)!=c){
           cout<<-1<<endl;
           return 0;
         }
      
   }
   string ans="";

   if(n!=1&&vec.at(0)==""){
       vec.at(0)="1";
   }
   rep(i,n){
       if(vec.at(i)==""){
           ans+="0";
       }else{
           ans+=vec.at(i);
       }
   }
   cout<<ans<<endl;

    
}
