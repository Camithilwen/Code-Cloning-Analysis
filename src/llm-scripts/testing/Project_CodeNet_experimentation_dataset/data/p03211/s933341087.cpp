#include <bits/stdc++.h>
#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

using namespace std;

int main(){
    io

    string s;
    cin >> s;

    int smaller = INT_MAX;
    for(int i(0); i<s.length()-2; i++){
        char temp[3];
        temp[0] = s[i];
        temp[1] = s[i+1];
        temp[2] = s[i+2];
        int n;
        sscanf(temp, "%d", &n);
        int dif = abs(753 - n);
        if(dif < smaller) smaller = dif;
    }
    cout << smaller << ENDL;

    
    return 0;
}