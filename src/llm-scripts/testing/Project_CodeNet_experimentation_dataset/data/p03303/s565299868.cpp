#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    int w;
    cin>>s>>w;
    for (int i=0;i+w<=s.size();i+=w) {
        cout<<s[i];
    }
    if (s.size()%w!=0) {
        reverse(s.begin(),s.end());
        string tmp=s.substr(0,s.size()%w);
        cout<<tmp[tmp.size()-1];
    }
    cout<<endl;
}