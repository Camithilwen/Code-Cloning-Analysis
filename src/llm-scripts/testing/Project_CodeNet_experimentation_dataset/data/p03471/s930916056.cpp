#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, y;
    cin >> n >> y;
    int ans10 = -1, ans5 = -1, ans1 = -1;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            int total = 10000*i + 5000*j + 1000*(n-i-j);
            if(total == y){
                ans10 = i;
                ans5 = j;
                ans1 = n-i-j;
            }
        }
    }

    cout << ans10 << " " << ans5 << " " << ans1 << endl;
}