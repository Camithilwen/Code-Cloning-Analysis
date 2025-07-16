#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N, Q;
    cin>>N>>Q;

    string S;
    vector<int> ac_cnt(N, 0);
    int cnt = 0;
    cin>>S;
    for(int i=0; i<N-1; i++){
        if(S[i]=='A' && S[i+1]=='C'){
            S[i]='a';
            cnt++;
        }
        ac_cnt[i+1] = cnt;
    }

    vector<int> ans;
    for(int i=0; i<Q; i++){
        int l, r;
        cin>>l>>r;

        if(l == 1){
            ans.push_back(ac_cnt[r-1]);
        }else{
            ans.push_back(ac_cnt[r-1] - ac_cnt[l-1]);
        }

    }

    // for(int a : ac_cnt){
    //     cout<<a<<endl;
    // }
    // cout<<"-------"<<endl;
    for(int a : ans){
        cout<<a<<endl;
    }
    return 0;
}