#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string a,b,c;
    cin >> n >> a >> b >> c;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i] && b[i] != c[i]){
            cnt++;
        }else if(a[i] == c[i] && b[i] != c[i]){
            cnt++;
        }else if(c[i] == b[i] && a[i] != c[i]){
            cnt++;
        }else if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]){
            cnt += 2;
        }
    }
    cout << cnt << endl;

    return 0;
}