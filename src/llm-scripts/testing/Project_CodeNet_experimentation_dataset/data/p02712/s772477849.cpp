#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define sci(x) int x; scanf("%d", &x);
#define TC(x) sci(x); while(x--)
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll sum = 0;
    for(int i=1;i<=n;i++){
        if(i%5!=0 && i%3!=0) sum+=i;
    }
    cout<<sum<<endl;
    return 0;
}
