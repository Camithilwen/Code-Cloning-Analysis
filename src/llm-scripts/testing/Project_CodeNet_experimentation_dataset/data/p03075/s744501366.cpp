#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[5], k, ans = 0;
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    cin >> k;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(a[i] < a[j] && a[j] - a[i] > k)
                ans++;
    if(ans)cout << ":(";
    else cout << "Yay!";
    return 0;
}