#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = s.at(0) - '0', b = s.at(1) - '0', c = s.at(2) - '0', d = s.at(3) - '0';
    for(int i = 0; i < 8;i++){
        bitset<3> s(i);
        vector<char> fugou(3); 
        int temp = a;
        if(s.test(0)) temp += b, fugou[0] = '+';
        else temp -= b, fugou[0] = '-';
        if(s.test(1)) temp += c, fugou[1] = '+';
        else temp -= c,  fugou[1] = '-';
        if(s.test(2)) temp += d, fugou[2] = '+';
        else temp -= d,  fugou[2] = '-';
        if(temp == 7){
            cout << a << fugou[0] << b << fugou[1] << c << fugou[2] << d << "=7" << endl;
            break;
        }
    }
    return 0;
}