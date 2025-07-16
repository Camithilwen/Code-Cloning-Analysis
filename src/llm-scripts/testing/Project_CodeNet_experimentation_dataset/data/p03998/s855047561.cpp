#include<bits/stdc++.h>
using namespace std;

int main(){
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    int tmp = 0;
    int num[3] = {0,0,0};
    while(num[tmp] < s[tmp].size()){
        num[tmp]++;
        tmp = s[tmp][num[tmp] - 1] - 'a';
    }
    cout << char('A' + tmp) << endl;
}