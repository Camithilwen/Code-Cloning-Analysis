#include <iostream>
#include <vector>

using namespace std;
bool isW(char c){
    return c=='W';
}
bool isX(char c){
    return c=='x';
}
int main(){//D問題
    int n;
    string s;
    cin >> n >> s;
    vector<char> t(n);
    char assum[4][2] = {{'S', 'S'}, {'S', 'W'}, {'W', 'S'}, {'W', 'W'}};
    for(int i=0;i<4;++i){
        t[0] = assum[i][0];
        t[1] = assum[i][1];
        for(int j=1;j<n-1;++j){
            t[j+1] = isW(t[j-1])^isX(s[j])^isW(t[j]) ? 'W' : 'S';
        }
        if(!(isW(t[n-2])^isX(s[n-1])^isW(t[n-1])^isW(t[0]) || isW(t[n-1])^isX(s[0])^isW(t[0])^isW(t[1]))){
            for(char c : t){
                cout << c;
            }
            return 0;
        }
    }
    cout << "-1";
    return 0;
}