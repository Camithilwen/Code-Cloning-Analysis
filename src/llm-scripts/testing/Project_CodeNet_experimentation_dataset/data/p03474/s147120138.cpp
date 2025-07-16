#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
    int a,b;
    string s;
    vector<char> lst(10);
    cin>>a>>b>>s;
    bool ans=true;
    // for(int i=0;i<s.size();i++){
    //     cin>>lst.at(i);
    // {
        
    for(int i=0;i<s.size();i++){     
        if (i!=a && s[i]=='-'){
            ans=false;
            break;
        }
        if (i==a && s[i]!='-'){
            ans=false;
            break;
        }
    }
    if(ans==true){
        cout<<"Yes"<<endl;    
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}