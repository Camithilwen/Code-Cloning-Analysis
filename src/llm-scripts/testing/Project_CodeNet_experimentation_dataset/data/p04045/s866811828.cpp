#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long K, std::vector<long long> D){
    long long ans = 0;
    for(long long i = N; i < 100000; ++i){
        //cout << i << endl;
        string S = to_string(i);
        bool check = true;
        for(auto s : S){
            for(auto d : D){
                string st{s};
                string ds = to_string(d);
                //cout << st << " " << ds << endl;
                if(st == ds){
                    //cout << "check!" << endl;
                    check = false;
                }
            }
        }
        if(check){
            //cout << i << endl;
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> D(K);
    for(int i = 0 ; i < K ; i++){
        scanf("%lld",&D[i]);
    }
    solve(N, K, std::move(D));
    return 0;
}
