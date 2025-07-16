#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    unsigned long long int n;
    cin>>n;
    cin>>s;
    if(n>=s.size())
        cout<<s;
    else{
        s.erase(s.begin()+n,s.end());
        s.append("...");
        cout<<s;
    }
}
