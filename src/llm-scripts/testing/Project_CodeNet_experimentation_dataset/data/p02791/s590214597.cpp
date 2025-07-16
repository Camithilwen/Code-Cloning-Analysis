#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N;cin>>N;
    int mini=N+1;
    int ans=0;
    for (int i = 0; i < N; i++){
        int P;cin>>P;
        if(P<=mini)ans++;
        mini=min(mini,P);
    }
    cout<<ans<<endl;
}