#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    unsigned long ans{~0UL};
    for(unsigned long i{0}, pa{~0UL}, a; i < N; ++i){
        cin >> a;
        if(pa + 1 < a)return 0 & puts("-1");
        if(pa + 1 == a)++ans;
        else ans += a;
        pa = a;
    }
    cout << ans << endl;
    return 0;
}