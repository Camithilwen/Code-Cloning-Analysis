#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)

int main(){
    int n;
    while (cin >> n, n){
        int v[10] = {};
        rep(i, n){
            int s = 0;
            rep(j, n){
                int t; cin >> t;
                printf("%5d", t);
                s += t;
                v[j] += t;
            }
            printf("%5d\n", s);
        }
        int s = 0;
        rep(i, n){
            printf("%5d", v[i]);
            s += v[i];
        }
        printf("%5d\n", s);
    }
}