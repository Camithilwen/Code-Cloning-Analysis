#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    if(l>=0)cout << (2*l+n-1)*n/2-l << endl;
    else if(n+l>0){
        cout << (2*l+n-1)*n/2 << endl;
    }
    else {
        cout << (2*l+n-1)*n/2-(l+n-1) << endl;
    }
    return 0;
}