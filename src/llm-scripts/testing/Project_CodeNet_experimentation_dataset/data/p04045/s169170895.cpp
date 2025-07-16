#include <bits/stdc++.h>
using namespace std;

bool check(int x, vector<int> &d){
    while(x > 0){
        int c = x % 10;
        for (int i=0; i<d.size(); i++){
            if(c == d[i]) return false;
        }
        x /= 10;
    }
    return true;
}


int main(void){
    // Your code here
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    for (int i=0; i<k; i++){
        cin >> d[i];
    }
    
    while(1){
        if(check(n, d)){
            cout << n << endl;
            return 0;
        }
        n++;
    }
}
