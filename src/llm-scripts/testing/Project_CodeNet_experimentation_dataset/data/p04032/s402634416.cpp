#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    long long n=s.size();
    for(long long i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
    }
    for(long long i=0;i<n-2;i++){
        if(s[i]==s[i+2]&&s[i]!=s[i+1]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}
