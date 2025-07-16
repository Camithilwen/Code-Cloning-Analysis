#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N; cin>>N;
    vec_int A(N);
    rep(i,N)cin>>A.at(i);


    int status = 1; 
    int tot = 0;
    for(int i=N-1;i>-1;i--){
        if(A.at(i)>i){
            cout<<-1<<endl;
            return 0;
        }

        if(status==1){
            tot += A.at(i);
            if(i>0){
                if(A.at(i-1)<A.at(i)){
                    status=0;
                    if(A.at(i)-A.at(i-1)>1){
            cout<<-1<<endl;
            return 0;

                    }
                }
            }
        }else{
            if(i>0){
                if(A.at(i-1)>=A.at(i))status=1;
            }
        }
    }
    cout<<tot<<endl;


    return 0;
}