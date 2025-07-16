#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    string s;
    bool flag = true;
    cin >> s;

    int len = s.size();
    int count_c = 0;
    int i_c = -1;
    
    if(s[0] != 'A') flag = false;
    
    for(int i=2;i<=len-2;i++){
        if(s[i] == 'C') {
            count_c++;
            i_c = i;
        }
    }
    
    if(count_c != 1) flag = false;
    
    for(int i=1;i<len;i++){
        if((int)s[i] >= 97 && (int)s[i] <= 121){
            
        }
        else{
            if(i != i_c) flag = false;
        }
    }
    
    if(flag){
        cout << "AC" << endl;
    }
    else{
        cout << "WA" << endl;
    }
}