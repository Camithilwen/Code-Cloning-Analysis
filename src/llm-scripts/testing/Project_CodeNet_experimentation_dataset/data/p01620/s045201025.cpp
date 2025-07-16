#include <bits/stdc++.h>
using namespace std;

string ab = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, key[100];
    string cip;
    while(cin >> n && n){
        for(int i = 0; i < n; i++){
            cin >> key[i];
        }
        cin >> cip;
        for(int i = 0; i < cip.size(); i++){
            int ind = lower_bound(ab.begin(), ab.end(), cip[i])-ab.begin();
            cout << ab[(ind - key[i%n] + 52) % 52];
        }
        cout << endl;
    }
    return 0;
}