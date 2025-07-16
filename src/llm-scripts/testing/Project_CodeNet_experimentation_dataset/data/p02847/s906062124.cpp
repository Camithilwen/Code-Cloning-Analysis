#include <bits/stdc++.h>
using namespace std;


void solve(std::string S){
    vector<string> yobi = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    for(int i = 0; i < yobi.size(); ++i){
        if(yobi[i] == S){
            cout << 7 - i << endl;
            break;
        }
    }
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
