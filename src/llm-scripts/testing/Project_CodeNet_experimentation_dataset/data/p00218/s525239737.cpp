#include<iostream>
using namespace std;

char classify(int m, int e, int j){
    if(m == 100 || e == 100 || j == 100)    return 'A';
    if((m+e)/2 >= 90)   return 'A';
    if((m+e+j)/3 >= 80) return 'A';
    if((m+e+j)/3 >= 70)    return 'B';
    if((m+e+j)/3 >= 50 && max(m,e) >= 80)   return 'B';
    return 'C';
}

int main(){
    int n;
    while(cin >> n, n){
        int m, e, j;
        for(int i = 0; i < n; i++){
            cin >> m >> e >> j;
            cout << classify(m,e,j) << endl;
        }
    }
    return 0;
}

