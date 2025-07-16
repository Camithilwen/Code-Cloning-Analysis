#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    /*
    int a, b;
    cin >> a >> b ;
    //*/

    //*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    //*/
    
    /*
    if( a < 6 ){
        cout << 0 << endl;
    } else if (a < 13){
        cout << b / 2 << endl;
    } else {
        cout << b << endl;
    }
    //*/
    
    cout << vec.at(0) + vec.at(1) << endl;

    return 0; 
}
