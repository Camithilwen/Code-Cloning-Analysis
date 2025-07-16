#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    map<string,int>s;
    map<string,int>t;
    int n,m;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        s[str]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>str;
        t[str]++;
    }
    int ans=0;
    for(auto i=s.begin();i!=s.end();i++){
        ans=max(ans,s[i->first]-t[i->first]);
    }
    cout<<ans<<endl;

    return 0;
}