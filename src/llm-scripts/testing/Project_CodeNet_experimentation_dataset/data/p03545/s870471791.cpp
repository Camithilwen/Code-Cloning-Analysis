#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;

bool ok(int a, int b, int c, int d, vector<char> s){
    int ans=0;
    if(s[1]=='+')
        ans = a+b;
    else
        ans = a-b;
    
    if(s[3]=='+')
        ans = ans + c;
    else
        ans = ans-c;

    if(s[5]=='+')
        ans += d;
    else
        ans -= d;
    
    if(ans==7)
        return true;
    else
        return false;
}

int main(){
    string s;
    cin >> s;
    int a=s[0]-'0';
    int b=s[1]-'0';
    int c=s[2]-'0';
    int d=s[3]-'0';
    

    char sign[2] = {'+', '-'};
    vector<char> ans(7);
    ans[0]=s[0];
    ans[2]=s[1];
    ans[4]=s[2];
    ans[6]=s[3];
    
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            for(int k=0; k<2; ++k){
                ans[1]=char(sign[i]);
                ans[3]=char(sign[j]);
                ans[5]=char(sign[k]);
                if(ok(a,b,c,d,ans)){
                    for(auto x:ans)
                        cout << x;
                    cout << "=7";
                    return 0;
                }
            }
        }
    }
}
