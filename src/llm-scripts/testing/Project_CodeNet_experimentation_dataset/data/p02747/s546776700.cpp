#include <iostream>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    if(S.length() % 2 == 0){
        for(int i=0;i<S.length();i=i+2){
            if(S[i] == 'h' && S[i+1] == 'i'){
                continue;
            }
            else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    else{
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
