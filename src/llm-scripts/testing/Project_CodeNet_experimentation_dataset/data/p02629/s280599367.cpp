#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void solve(){
    ll n;
    cin>>n;
    ll rem, num = 26;
    string str="";

        while(n != 0){
            // cout<<1<<endl;
            rem = n%26;
            if(rem == 0){
                str += 'z';
                n = n/26;
                n--;
            }
            else{
                rem--;
                n = n/26;
                char ch = 'a';
                ch += rem;
                str += ch;
            }
            
            
            // n;
        }
    reverse(str.begin(),str.end());
    cout<<str<<endl;


}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q;
    q=1;
    // cin>>q;
    while(q--) solve();


    return 0;
}
