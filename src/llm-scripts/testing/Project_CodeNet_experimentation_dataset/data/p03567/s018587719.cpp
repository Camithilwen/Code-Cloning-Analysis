#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i=0;
    int ac=0;

    while((i<s.size()-1)&&(ac==0)){
        if((s.at(i)=='A')&&(s.at(i+1)=='C')){
            ac++;
        }
        i++;
    }
    if(ac==1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}