#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,char>> array(m);
    for(int i=0;i<m;i++) cin >> array.at(i).first >> array.at(i).second;
    int s,g;
    s = 1;
    for(int i=0;i<n-1;i++) s*=10;
    g = s * 10;
    if(n == 1) s = 0;
    for(int i=s;i<g;i++){
        string str_number = to_string(i);
        bool flag = true;
        for(int j=0;j<m;j++){
            if(str_number.at(array.at(j).first - 1) != array.at(j).second) flag = false;
            
        }
        if(flag){
                cout << str_number << endl;
                return 0;
            }
    }
    cout << -1 << endl;
}