#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int a , b;
    cin >> a >> b;
    int c = 1 , ans = 0;
    while(c<b){
        c--;
        c += a;
        ans++;
    }
    cout<<ans;
}