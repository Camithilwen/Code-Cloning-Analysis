#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    string str;
    cin >> str;

    int al[26] = {0};
    roop(i, str.length()) al[str[i]-'a']++;

    roop(i, 26){
        if(al[i] == 0){
            str += (char)(i+'a');
            cout << str << endl;
            return 0;
        }
    }

    string t = str;
    if(next_permutation(t.begin(), t.end()) == false){
        cout << -1 << endl;
        return 0;
    }


    roop(i, str.length()-1){
        cout << t[i];
        if(t[i] != str[i]) break;
    }

    cout << endl;

    return 0;
}