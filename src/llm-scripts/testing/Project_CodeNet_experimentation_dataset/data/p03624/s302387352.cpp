#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int>X(26,0);
    string S;cin>>S;
    for(long long i=0;i<S.size();i++){
        X[(int)S[i]-97]++;
    }
    for(long long i=0;i<26;i++){
        if(X[i]==0){
            int ans=i+97;
            cout<<(char)ans<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}