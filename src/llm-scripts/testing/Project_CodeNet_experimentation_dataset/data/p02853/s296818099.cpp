#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin >> x>>y;
    vector<int> a(206);

    a.at(1)=300000;
    a.at(2)=200000;
    a.at(3)=100000;

    if((x==1)&&(y==1)){
        cout << 1000000 <<endl;
    }
    else{
        cout << a.at(x) + a.at(y) << endl;
    }
    return 0;
}