#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    string ans;
    for (char c: s)
        if (c == 'S')   ans += c;
        else if (ans.size() && ans.back() =='S')    ans.pop_back();
        else ans += c;
    cout<<ans.size()<<endl;
}
