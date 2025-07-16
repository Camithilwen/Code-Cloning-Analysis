#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    string s;
    
    cin >> k >> s;
    
    if (s.size()>k) {
        string sub = s.substr(0, k);
        cout << sub << "..." <<endl;
    }
    else{
        cout << s <<endl;
    }
    
}
