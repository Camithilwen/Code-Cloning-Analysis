#include <bits/stdc++.h>
using namespace std;

queue<char> que[3];

int rec(int i){
    if(que[i].empty()) return i;
    char q = que[i].front();
    que[i].pop();
    return rec(q - 'a');
}

int main(){
    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            que[i].push(s[j]);
        }
    }
    cout << (char)(rec(0) + 'A') << endl;
    return 0;
}
