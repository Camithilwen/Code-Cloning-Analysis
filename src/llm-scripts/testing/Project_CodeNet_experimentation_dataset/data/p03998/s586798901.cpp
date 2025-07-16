// 3人でカードゲームイージー  /  理解できた
// #16973056
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    vector<int> i(3, 0);
    char c[]={'A', 'B', 'C'};
    int t=0;
    while(true){
        if(i[t]==s[t].size()){
            cout << c[t] << endl;
            return 0;
        }
        i[t]++;
        t=s[t][i[t]-1]-'a';
        
    }
}