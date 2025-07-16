#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> W(n, 0);
    vector<int> E(n, 0);

    string s;
    cin>>s;

    if(s[0] == 'W'){
        W[0]++;
    }
    if(s[0] == 'E'){
        E[0]++;
    }

    for(int i=1; i<n; i++){
        if(s[i] == 'W'){
            W[i] = W[i-1] + 1;
        }else{
            W[i] = W[i-1];
        }
        if(s[i] == 'E'){
            E[i] = E[i-1] + 1;
        }else{
            E[i] = E[i-1];
        }
    }

    int ans = E[n-1] - E[0];
    for(int i=1; i<n; i++){
        ans = min(ans, E[n-1]-E[i] + W[i-1]);      
    }
    cout<<ans<<endl;
    return 0;
}