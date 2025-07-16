/*
      author : nishi5451
      created: 11.08.2020 00:36:47
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string a,b,c;
    cin >> a >> b >> c;
    if(*a.rbegin()==*b.begin() && *b.rbegin()==*c.begin()){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}