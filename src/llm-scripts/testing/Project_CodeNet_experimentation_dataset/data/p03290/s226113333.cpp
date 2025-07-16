//
// Created by TakahiroYamaji on 2020/08/13.
//
#include<iostream>
#include<queue>
typedef long long ll;
int D;
ll G;
int p[11];
ll c[11];

ll solve(int i){
    ll ans = 0;
    ll sum = 0;
    std::priority_queue<ll>P;
    for (int j=0;j<D;j++){
        //std::cout << j << std::endl;
        if (i & (1 << j)){
            sum += (j + 1) * 100 * p[j] + c[j];
            ans += p[j];
        }else{
            P.push(j);
        }
    }

    //微調整
    while (!P.empty()){
        int s = P.top();
        P.pop();
        for (int i=1;i<=p[s];i++){
            if (sum >= G){
                return ans;
            }
            ans++;
            sum += (s + 1) * 100;
        }
    }
    //std::cout << sum << std::endl;
    if (sum >= G){
        return ans;
    }else{
        return 1e12;
    }
}

int main(){
    std::cin >> D >> G;
    for (int i=0;i<D;i++){
        std::cin >> p[i] >> c[i];
    }

    ll min_v = 1e15;
    //bit 全探索
    for (int i=0;i<(1 << D);i++){
        ll ans1 = solve(i);
        //std::cout << ans1 << std::endl;
        if (min_v > ans1){
            min_v = ans1;
        }
    }
    std::cout << min_v << std::endl;
    return 0;
}

