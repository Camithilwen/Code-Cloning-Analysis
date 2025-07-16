#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>A,B;
    for(int i=0;i<2;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<2;i++){
        int b;
        cin >> b;
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    cout << A.at(0) + B.at(0) << '\n';
    return 0;
}