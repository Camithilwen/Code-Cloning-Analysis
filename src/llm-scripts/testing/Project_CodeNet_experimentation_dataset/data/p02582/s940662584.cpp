#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin>>s;
    int ans = 0;
    int ma = INT_MIN;
    for(int i=0;i<s.size();i++) {
        if(s[i] == 'R') {
            ans++;
        }
        else {
            ma = max(ma, ans);
            ans = 0;
        }
    }
     ma = max(ma, ans);

    cout<<ma<<endl;
}
