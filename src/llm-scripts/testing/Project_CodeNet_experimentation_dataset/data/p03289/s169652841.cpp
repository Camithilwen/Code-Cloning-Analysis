#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool flg = true;
    int c_cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(i==0){
            if(s.at(i)!= 'A'){
                flg = false; break;
            }  
        }else if(isupper(s.at(i))){
            if(i==1 || i==s.length()-1 || s.at(i) != 'C'){
                flg = false; break;
            }
            c_cnt++;
        }  
    }
    if(c_cnt != 1)
        flg = false;
    
    if(flg) cout << "AC" << endl;
    else cout << "WA" << endl;

    return 0;
}