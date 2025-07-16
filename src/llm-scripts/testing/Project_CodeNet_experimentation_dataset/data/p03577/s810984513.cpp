#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    int len = s.length();
    for(int i = 0; i < len-8; i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}