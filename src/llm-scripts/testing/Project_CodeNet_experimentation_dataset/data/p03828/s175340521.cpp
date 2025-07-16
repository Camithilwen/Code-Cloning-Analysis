#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    long long n,ans = 1;
    map<int,long long> prime;
    cin >> n;
    for(int num = n;2 <= num;num--){
        int buf = num;
        for(int i = 2;i * i<= n;i++){
            int count = 0;
            while(buf % i == 0)buf /= i,count++;
            prime[i] += count;
        }
        if(buf != 1)prime[buf]++;
    }
    for(auto pri : prime){
        ans = ans * (pri.second + 1) % MOD;
    }
    cout << ans << endl;
}