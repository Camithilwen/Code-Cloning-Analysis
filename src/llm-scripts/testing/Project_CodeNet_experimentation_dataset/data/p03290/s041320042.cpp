#include <bits/stdc++.h>

int main(){
    long long D, G;
    std::cin >> D >> G;
    G /= 100;
    std::vector< int > P(D);
    std::vector< int > C(D);
    for(int i=0; i<D; i++){
        std::cin >> P[i] >> C[i];
        P[i];
        C[i] /= 100;
    }
    
    std::vector< std::vector< int > > dp(D+1, std::vector< int >(G+1, 1e8));
    dp[0][0] = 0;
    
    for(int i=1; i<=D; i++){
        std::vector< int > cur(G+1, 1e8);
        cur[0] = 0;
        for(int j=1; j<=G; j++){
            if(i * P[i-1] + C[i-1] < j){
                break;
            }else if(i * P[i-1] < j){
                cur[j] = P[i-1];
            }else{
                cur[j] = j / i + (j % i != 0);
            }
        }
        int index_a1 = 1, index_a2 = 0, index_b1 = 0, index_b2 = 1;
        dp[i][0] = 0;
        while(index_a1 + index_a2 <= G){
            int a = dp[i-1][index_a1] + cur[index_a2];
            int b = dp[i-1][index_b1] + cur[index_b2];
            if(a > b){
                dp[i][index_a1 + index_a2] = b;
            }else{
                dp[i][index_a1 + index_a2] = a;
            }
            
            if(index_a1 == G || dp[i-1][index_a1+1] >= 1e8){
                index_a2++;
            }else{
                index_a1++;
            }
            
            if(index_b2 == G || cur[index_b2+1] >= 1e8){
                index_b1++;
            }else{
                index_b2++;
            }
        }
    }
    
    
    std::cout << dp[D][G] << std::endl;
    
    
    return 0;
    
}
