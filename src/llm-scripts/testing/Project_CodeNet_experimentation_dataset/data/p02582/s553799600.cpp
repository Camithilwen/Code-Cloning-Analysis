#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    string S;
    cin >> S;
    
    int i, l, count, max;
    l = S.length();
    count = 0;
    max = 0;
    
    for (i = 0; i < l; i++){
        
        if (S.at(i) == 'S'){
            count = 0;
        } else {
            count += 1;
            if (count > max) max = count;
        }
    }
    
    cout << max << "\n";
    
    return 0;
}
