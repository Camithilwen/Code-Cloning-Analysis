#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<" ";

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    double a[n];
    double num=1e9,sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    for(int i=0;i<n;i++){
        num=min(num,abs(a[i]-sum));
    }
    for(int i=0;i<n;i++){
        if(abs(sum-a[i])==num){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}
