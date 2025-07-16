#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int K,T; cin >> K >> T;
    int a[T];
    for(int i=0;i<T;i++){
        cin >> a[i];
    }
    sort(a,a+T);
    int sum=0;
    for(int i=0;i<T-1;i++){
        sum+=a[i];
    }
    int ans=max(a[T-1]-1-sum,0);
    cout << ans << endl;
}