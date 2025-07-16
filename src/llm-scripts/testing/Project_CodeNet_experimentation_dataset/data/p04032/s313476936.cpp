#include <bits/stdc++.h>
#define MAXN 100010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const int mod = 1e9 + 7;

int main (){
    string s;

    cin >> s;

    int n = s.size();

    for (int i=0; i<n-2; i++){
        if (s[i+1] == s[i] || s[i+2] == s[i]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    if (s[n-1] == s[n-2]){
        cout << n-1 << " " << n << endl;
    }
    else cout << "-1 -1" << endl;
    
    return 0;
}