#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <functional>
#include <complex>

using namespace std;

const int INF = (1<<30) - 1;

string table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while(cin >> n, n){
        vector<int> key(n);
        for(int i=0; i<n; i++)
            cin >> key[i];
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            char &c = s[i];
            c = table[(table.find_first_of(c)-key[i%n]+52)%52];
        }
        cout << s << endl;
    }
    
    return 0;
}