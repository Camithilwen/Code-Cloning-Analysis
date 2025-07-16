#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll a,b,i,cnt=0;
    scanf("%lld %lld", &a, &b);
    while(a<=b){
        string s;
        s = to_string(a);
        if(s[0]==s[4] && s[1]==s[3]){
            cnt++;
        }
        a++;
    }
    printf("%lld\n", cnt);
    return 0;
}