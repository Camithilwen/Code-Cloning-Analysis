#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string str = to_string(N);
    string res;

    if(str.find("7") != string::npos){
        res = "Yes";
    } else {
        res = "No";
    }

    cout << res << endl;

    return 0;
}