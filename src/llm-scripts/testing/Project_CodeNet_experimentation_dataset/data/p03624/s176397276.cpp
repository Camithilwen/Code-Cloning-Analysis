#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    string az="abcdefghijklmnopqrstuvwxyz";
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    
    int i=0,j=0;
    rep(j,s.size()){
        if(az[i]==s[j])i++;
        if(i==26){cout << "None" << endl;return 0;}
    }
    
    cout << az[i];
    
	return 0;
}