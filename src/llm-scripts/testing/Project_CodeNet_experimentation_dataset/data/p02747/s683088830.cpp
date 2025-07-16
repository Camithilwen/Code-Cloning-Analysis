#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >> S;
    bool a=true;
    if(S.size()%2==1) a=false;
    else for(int i=0;i<S.size()/2;i++){
        if(S.at(i*2)!='h'||S.at(i*2+1)!='i') a=false;
    }
    if(a)cout << "Yes" << endl;
    else cout << "No" << endl;
}
