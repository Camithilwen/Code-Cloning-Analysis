#include <bits/stdc++.h>

int main(){
    int N, T;
    std::cin >> N >> T;
    std::vector< std::pair< int, int > > AB(N);
    for(int i=0; i<N; i++){
        std::cin >> AB[i].first >> AB[i].second;
    }
    
    std::sort(AB.begin(), AB.end());
    
    std::vector< std::vector< int > > dp(N + 1, std::vector< int >(T));
    dp[0].assign(T, 0);
    int max = 0;
    for(int i=1; i<N+1; i++){
        if(max < dp[i-1][T-1] + AB[i-1].second){
            max = dp[i-1][T-1] + AB[i-1].second;
        }
        for(int j=0; j<T; j++){
            if(j < AB[i-1].first){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-AB[i-1].first] + AB[i-1].second);
            }
        }
    }
    
    std::cout << max << std::endl;
    
    return 0;
}

