#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    string s;
    cin >> a >> b;
    cin >> s;
    vector<char> num{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if(s.at(a) == '-'){
        vector<bool> judge2  (s.size(), false);
        judge2.at(a) = true;
        for(int i = 0;i < s.size();i++){
            for(int j = 0;j <  num.size();j++){
                if(i == a)continue;
                else if(s.at(i) == num.at(j))judge2.at(i) = true;
            }
        }
        bool judge = true;
        for(int i = 0;i < judge2.size();i++){
            if(!judge2.at(i))judge = false;
        }
        if(judge)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
}