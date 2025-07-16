#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

bool check(long long a,long long b,long long c){
    return true;
}

int main(){
    string str;

    cin >> str;

    if(str.size()%2!=0){
        cout << "No" << endl;
        return 0;
    }
    for(int i=0; i<str.size()-1; i+=2){
        if(str.at(i)=='h' && str.at(i+1)=='i'){
            continue;
        }
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}