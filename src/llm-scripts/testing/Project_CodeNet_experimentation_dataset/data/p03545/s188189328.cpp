#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector <int> s(4);
    rep(i,4){
        s[3-i] = n%10;
        n /= 10;
    }

    vector <char> ansi(3);
    for(int i=0; i<(1<<3); i++){
        bitset<3> a(i);
        int tmp = s[0];
        for(int j=0; j<3; j++){
            if(a.test(j)){
                tmp += s[j+1];
                ansi[j] = '+';
            }
            else{
                tmp -= s[j+1];
                ansi[j] = '-';
            }
        }
        if(tmp == 7) break;
    }

    rep(i,3){
        cout << s[i] << ansi[i];
    }
    cout << s[3];
    cout << "=7" << endl;



}   

