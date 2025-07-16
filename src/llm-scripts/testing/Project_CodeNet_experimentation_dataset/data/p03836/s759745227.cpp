#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string ans="";
    for(int i=0; i<ty-sy; i++){
        ans+="U";
    }
    for(int i=0; i<tx-sx; i++){
        ans+="R";
    }
    for(int i=0; i<ty-sy; i++){
        ans+="D";
    }
    for(int i=0; i<tx-sx; i++){
        ans+="L";
    }
    ans+="D";
    for(int i=0; i<tx-sx+1;i++){
        ans+="R";
    }
    for(int i=0; i<ty-sy+1; i++){
        ans+="U";
    }
    ans+="L";
    ans+="U";
    for(int i=0; i<tx-sx+1; i++){
        ans+="L";
    }
    for(int i=0; i<ty-sy+1; i++){
        ans+="D";
    }
    ans+="R";
    cout << ans << endl;
}