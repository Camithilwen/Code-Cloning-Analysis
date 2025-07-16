#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

int main(){
    cin >> n;
    string ans = "";
    while(n>0){
        n--;
        ans = char((n)%26+'a')+ans;
        n/=26;
    }
    cout << ans << endl;
}
