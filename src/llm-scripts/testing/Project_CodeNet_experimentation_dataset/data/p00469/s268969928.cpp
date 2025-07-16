#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);   

    int n,k;

    
    while(cin >> n >> k){
        if(!n && !k) break;

        int card[n];
        rep(i,n) cin >> card[i];

        sort( card, card + n );

        int ans = 0;
        map<int,int> memo;
        do{
            int temp = 0;
            rep(i,k){
                temp *= 10;
                if(card[i]>9) temp *= 10;
                temp += card[i];
            }
            if(memo[temp] == 0) ans++;
            memo[temp] = 1;
        }while(next_permutation( card, card + n ));

        cout << ans << endl;
    }

    return 0;
}
