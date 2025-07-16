#include <bits/stdc++.h>

int modnum = 1000000007;

int main(){
    int N;
    std::cin >> N;
    std::vector< int > cnt(N+1, 0);
    cnt[0] = 3;
    long long ans = 1;
    for(int i=0; i<N; i++){
        int a;
        std::cin >> a;
        int tmp = cnt[a] - cnt[a + 1];
        ans *= (long long)tmp;
        ans = ans % modnum;
        cnt[a + 1]++;
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
}

