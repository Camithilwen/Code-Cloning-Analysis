#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll l,r;
    scanf(" %lld %lld",&l,&r);
    vector<int> modulos(2019,0);
    for(int i = l, j = 0; i <= r && j <= 10000;++i,++j)
        ++modulos[i%(2019ll)];
    int ans = 10000;
    for(int i = 0; i < modulos.size();++i){
        for(int j = i; j < modulos.size();++j){
            if(i == j && modulos[i] > 1)
                ans = min(ans,(i*i)%2019);
            else if(i != j && modulos[i] && modulos[j])
                ans = min(ans,(i*j)%2019);
        }
    }
    printf("%d\n",ans);
    return 0;
}