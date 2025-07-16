#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long M, std::vector<long long> p, std::vector<std::string> S){
    vector<long long> ac(N+1, 0);
    vector<long long> wa(N+1, 0);
    for(int i = 0; i < M; ++i){
        if(ac[p[i]] == 0){
            if(S[i] == "AC") ac[p[i]] = 1;
            else wa[p[i]] += 1;
        }
    }
    //for(auto i : ac) cout << "AC: " << i << endl;
    //for(auto i : wa) cout << "WA: " << i << endl;
    long long cnt_wa = 0;
    for(int i = 0; i < N + 1; ++i){
        if(ac[i] == 1) cnt_wa += wa[i]; 
    }
    cout << accumulate(ac.begin(), ac.end(), 0LL) << " " << cnt_wa << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> p(M);
    std::vector<std::string> S(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&p[i]);
        std::cin >> S[i];
    }
    solve(N, M, std::move(p), std::move(S));
    return 0;
}
