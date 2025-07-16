#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt=0;
    for(int i=1; i<n; i++){
        if(s.at(i) == 'E') cnt++;
    }  
    vector<int> change(n);
    change.at(0) = cnt;
    for(int i=1; i<n; i++){
        change.at(i) = change.at(i-1);
        if(s.at(i-1) == 'W') change.at(i)++;
        if(s.at(i) == 'E') change.at(i)--;
    }
    int ans=change.at(0);
    for(int i=0; i<n; i++){
        ans = min(ans, change.at(i));
    }
    cout << ans << endl;
}