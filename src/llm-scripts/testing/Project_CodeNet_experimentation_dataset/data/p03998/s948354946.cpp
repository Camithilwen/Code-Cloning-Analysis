#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string sa,sb,sc;
    cin >> sa >> sb >> sc;
    queue<char> qa,qb,qc;
    for(int i = 0; i < sa.size(); i++) qa.push(sa[i]);
    for(int i = 0; i < sb.size(); i++) qb.push(sb[i]);
    for(int i = 0; i < sc.size(); i++) qc.push(sc[i]);
    qa.push('w'),qb.push('w'),qc.push('w');
    char x=qa.front();
    qa.pop();
    while(!qa.empty() && !qb.empty() && !qc.empty()){
        if(x=='a'){
            x=qa.front();
            qa.pop();
        }
        if(x=='b'){
            x=qb.front();
            qb.pop();
        }
        if(x=='c'){
            x=qc.front();
            qc.pop();
        }
    }

    if(qa.empty()) cout << 'A' << endl;
    else if(qb.empty()) cout << 'B' << endl;
    else cout << 'C' << endl;

    return 0;
}