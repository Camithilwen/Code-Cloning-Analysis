#include <iostream>
using namespace std;

long long int get_digit(long long int l){
    long long int digit = 0;
    
    while(l != 0){
        l /= 10;
        digit++;
    }
    
    return digit;
}

int main(void){
    // Your code here!
    long long int n;
    cin >> n;
    
    long long int j;
    long long int x,y,z;
    long long int ans = 20000000000000;
    
    for(long long int i=1; i*i <= n;i++){//iは０からエラー
        if(n%i == 0){
            j = n/i;
            x = get_digit(i);
            y = get_digit(j);
            z = max(x,y);
            if(z < ans){
                ans = z;
            }
        }
    }
    
    cout << ans << endl;
}
