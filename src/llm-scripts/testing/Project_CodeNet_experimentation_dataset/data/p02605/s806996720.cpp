#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
#include <random>
#include <bitset>
#include <list>
// #include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
typedef long long ll;
typedef double lf;
typedef short int si;



void Main(){
    ll N, x, y;
    string u;
    map<ll,map<string, set<ll>>> leftup_group;
    map<ll,map<string, set<ll>>> rightup_group;
    map<ll,map<string, set<ll>>> updown_group;
    map<ll,map<string, set<ll>>> lr_group;
    sll(N);
    rep(i, N){
        sll(x);
        sll(y);
        cin >> u;
        leftup_group[x+y][u].insert(x);
        rightup_group[x-y][u].insert(x);
        if(u=="U" || u == "D"){
            updown_group[x][u].insert(y);
        }else if(u=="R" || u == "L"){
            lr_group[y][u].insert(x);
        }
    }
    // x + y -> u & r ^ u_x >= r_x , d & l ^ d_x <= l_x
    // x - y -> u & l ^ u_x <= l_x , d & r ^ d_x >= r_x
    ll min_v = 1e15;
    for(auto& p:leftup_group){
        auto each_g = p.second;
        for(auto c:each_g["R"]){
            auto iter = each_g["U"].upper_bound(c);
            if(iter != each_g["U"].end()){
                // cout << "x+y, R & U, R_x="<<c << " U_x="<<*iter<<endl;
                ll v = *iter;
                min_v = min((v-c)*10, min_v);
            }
        }

        for(auto c:each_g["D"]){
            auto iter = each_g["L"].upper_bound(c);
            if(iter != each_g["L"].end()){
                // cout << "x+y, L & D, L_x="<<c << " D_x="<<*iter<<endl;
                ll v = *iter;
                min_v = min((v-c)*10, min_v);
            }
        }
    }

    for(auto& p:rightup_group){
        auto each_g = p.second;
        for(auto c:each_g["U"]){
            auto iter = each_g["L"].upper_bound(c);
            if(iter != each_g["L"].end()){
                // cout << "x-y, U & L, U_x="<<c << " L_x="<<*iter<<endl;
                ll v = *iter;
                min_v = min((v-c)*10, min_v);
            }
        }

        for(auto c:each_g["R"]){
            auto iter = each_g["D"].upper_bound(c);
            if(iter != each_g["D"].end()){
                // cout << "x+y, R & D, R_x="<<c << " D_x="<<*iter<<endl;
                ll v = *iter;
                min_v = min((v-c)*10, min_v);
            }
        }
    }

    for(auto& p:updown_group){
        auto each_g = p.second;
        for(auto c:each_g["U"]){
            auto iter = each_g["D"].upper_bound(c);
            if(iter != each_g["D"].end()){
                ll v = *iter;
                min_v = min((v-c)*5, min_v);
            }
        }
    }

    for(auto& p:lr_group){
        auto each_g = p.second;
        for(auto c:each_g["R"]){
            auto iter = each_g["L"].upper_bound(c);
            if(iter != each_g["L"].end()){
                ll v = *iter;
                min_v = min((v-c)*5, min_v);
            }
        }
    }

    if(min_v == 1e15){
        cout << "SAFE" <<endl;
    }else{
        cout << min_v <<endl;
    }
    
}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}