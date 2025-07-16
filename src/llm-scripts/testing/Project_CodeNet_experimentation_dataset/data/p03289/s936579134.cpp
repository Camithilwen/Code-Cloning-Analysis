#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    int cnt = 0;
    for(int i = 2; i < s.size()-1; i++){
        if(s[i] == 'C') {
            cnt++;
            if(cnt == 1) s[i] = 'c';
        }
    }
    if(cnt != 1){
        puts("WA");
        return 0;
    }
    for(int i = 0; i < s.size(); i++){
        if(i == 0) {
            if(s[i] != 'A'){
                puts("WA");
                return 0;
            }
        }
        else{
            if(s[i] - 'a' < 0){
                puts("WA");
                return 0;
            }
        }
    }
    puts("AC");
    return 0;
}