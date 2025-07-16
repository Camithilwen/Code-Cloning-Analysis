#include<bits/stdc++.h>
using namespace std;
int main(){
 int K;
 string S;
 cin>>K>>S;
 int a=S.size();
 if(a<=K){
   cout<<S<<endl;
 }
 else{
   for(int i=0;i<K;i++){
     cout<<S.at(i);
   }
    cout<<"..."<<endl;
 }
}