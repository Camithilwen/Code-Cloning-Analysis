#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define l long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i]}
using namespace std;
int main(){
    FAST
    int n; cin >> n;
    int x;
    int result=0;
    while(n!=0){
        x=n%10;
        if(x==7){
            result=1;
        }
        n=n/10;
    }
    if(result==1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}
