#include <bits/stdc++.h>
using namespace std;
int const MX = 2e5 + 2, MOD = 1e9 + 7;

int main()
{
    int t = 1;
//    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l[101];
        for(int i = 0; i < n; i++){
            cin>>l[i];
        }
        int cnt = 0;
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n-1; j++){
                for(int k = j + 1; k < n; k++){
                    if(l[i] == l[j] || l[i] == l[k] || l[j] == l[k]) continue;
                    if(l[i] + l[j] > l[k] && l[i] + l[k] > l[j] && l[k] + l[j] > l[i]) cnt++;
                }
            }
        }
        cout<<cnt;
    }
}


