/* FUCK U*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
using namespace std;
void solve(){
    int n,k,count;
   
    cin>>n>>k;
    for(int i=n;i<=k;++i){
       string str=to_string(i);
        if(str.at(0)==str.at(4) && str.at(1)== str.at(3))
            count++;
    }
    cout<<count<<endl;    

}
int main(){
 
   ios::sync_with_stdio(false);
  cin.tie(0);
     solve();
}