#include<bits/stdc++.h>

using namespace std;

int main(){

    string input;
    int tmp = 0;
    char op[3] = {'+','+','+'};

    cin >> input;
  
    for(int bit = 0; bit < (1<< 3); bit++){
        tmp = 0;
        for(int i = 0;i<3;i++){
            if(bit & (1 << i)){
                op[i] = '-';
                tmp += (input[i+1] - '0') * (-1);
            }else{
                op[i] = '+';
                tmp += (input[i+1] - '0');
            }
        }
        tmp += input[0] - '0';
        if(tmp == 7)break;
    }

    for(int i = 0; i<3;i++){
        cout << input[i] << op[i];
    }

    cout << input[3] << "=7" << endl;

    return 0;
}