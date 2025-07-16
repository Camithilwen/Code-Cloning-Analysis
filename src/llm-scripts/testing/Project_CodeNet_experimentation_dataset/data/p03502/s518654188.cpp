#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N ;
    string str = to_string(N);
    int length= str.size();
    int div=0;

    for(int i=0; i<length; i++){
        div+=(int)(str[i] - '0');
    }
    if(N%div == 0){
        cout<< "Yes" <<endl;
    }else{
        cout<< "No" <<endl;
    }
}