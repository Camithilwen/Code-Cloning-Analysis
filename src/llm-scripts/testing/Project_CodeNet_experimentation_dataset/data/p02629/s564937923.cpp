#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    long long N,a;
    int Z=26; //26^nで次のアルファベットの桁に移る
    string ans ="";
    cin >> N ;
    while(N>0){
        N--;
        a=N%Z;
        N/=Z;
        ans+='a'+a; //aから割ったあまりの分文字コードを移動する
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}