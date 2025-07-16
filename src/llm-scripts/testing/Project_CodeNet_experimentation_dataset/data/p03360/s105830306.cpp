#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(3);
    int k;
    cin >> a[0] >> a[1] >> a[2];
    cin >> k;
    
    int check;
    int amax=max({a[0],a[1],a[2]});
    for(int i=0;i<3;i++){
        if(amax==a[i]) check=i;
    }

    for(int i=0;i<k;i++) amax*=2;
    cout << a[0]+a[1]+a[2]-a[check]+amax << endl;
}