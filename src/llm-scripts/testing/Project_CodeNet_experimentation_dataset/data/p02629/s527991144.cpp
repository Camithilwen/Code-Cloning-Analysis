#include <bits/stdc++.h>
using namespace std;

int main(){
    long N;
    cin >> N;
    N--;
    string name = "";
    char digit = 'a';
    while (N >= 0) {
        if (N % 26 != 0) {
            digit = 'a' + N % 26;
        } else {
            digit = 'a';
            
        }
        name = digit + name;
        N = N / 26 - 1;
        
    }
    cout << name << endl;
}
