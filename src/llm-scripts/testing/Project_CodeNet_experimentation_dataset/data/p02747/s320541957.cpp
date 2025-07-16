#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n = s.length();
    if(n%2!=0) {
        cout<<"No\n";
        return 0;
    }
    for(int i =0;i<n;i+=2)
    {
       if(s[i]=='h' && s[i+1]=='i') continue;
       else{
           cout<<"No\n";
           return 0;
       }
    }
    cout<<"Yes\n";
    return 0;
}