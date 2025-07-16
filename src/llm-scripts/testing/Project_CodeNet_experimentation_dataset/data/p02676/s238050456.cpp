#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N = 2e5+5 ;
//😁😁😁😁😁😁😁😁😁😁😁

void Never_give_up()

{
    int k; cin>>k;
     string s; cin>>s;

    if(s.size()<=k) cout<<s;
    else
    {
        for(int i=0;i<k;++i) cout<<s[i];
        cout<<"...";
    }
}

signed main() {
ios::sync_with_stdio(false);
cin.tie(0);


Never_give_up();


 return 0;
}


