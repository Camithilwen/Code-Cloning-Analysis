#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;
int main(void){
    int n,q; cin >> n >> q;
    string S; cin >> S;
    vector<int> sum(n+1,0);
    int i = 0;
    while (i < n) {
        if (S[i] == 'A' && S[i+1] == 'C') {
            sum[i+1] = sum[i] + 1;
        } else{
            sum[i+1] = sum[i];
        } 
        i++;
    }
    i = 0;
    while (i < q) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        cout << sum[tmp2] - sum[tmp1] << endl;
        i++;
    }
}
