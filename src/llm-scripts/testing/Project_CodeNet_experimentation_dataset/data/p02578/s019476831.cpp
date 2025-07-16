//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    long long int n,i,j,res = 0,temp;
    cin >> n;
    long long int a[n];
    for(i = 0;i<n;i++) {
        cin >> a[i];
        if(i>0){
            temp = a[i] - a[i-1];
            if(temp < 0) {
                res += (-1 * temp);
                a[i] += (-1*temp);
            }
        }
    }
        cout << res << endl;
    return 0;
}