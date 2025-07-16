#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,i,ans=0,p,q,r,s;
    cin >> A >> B;
    for(i=A;i<=B;i++){
        p=i%10;
        q=(i/10)%10;
        r=(i/1000)%10;
        s=(i/10000)%10;
        if(p==s&&q==r){
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}