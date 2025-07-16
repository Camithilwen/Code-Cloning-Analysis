#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long

int main(){
    int k;
    string s;
    cin >> k >> s;
    if(s.length() <= k){
        cout << s << endl;
    }else if(s.length() > k){
        rep(i,k){
        cout << s[i] ;
        }
        cout << "..." << endl;
    }
}