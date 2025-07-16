#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
typedef long long int ll;
const int INF = 1000000000;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
    string s;
    while(getline(cin, s)){
        rep(i, 26){
            for(char& c : s){
                if(isalpha(c)){
                    if(c != 'z') ++c;else c = 'a';
                }
            }
            if(s.find("that") != string::npos || s.find("this") != string::npos || s.find("the") != string::npos){
                cout << s << endl;
            }
        }
    }
    return 0;
}