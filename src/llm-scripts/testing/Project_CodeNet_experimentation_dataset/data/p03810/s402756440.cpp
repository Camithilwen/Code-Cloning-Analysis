#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long llint;
typedef pair < int, int> pii;
typedef pair < llint, llint> pll;
 
const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
 
int n,a[N],nep,ind;
llint sum = 0;
 
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]&1) {nep++;ind=i;}
        sum += (llint)a[i];
    }
    for(int koji = 1;;koji = !koji){
        int allgcd = a[0];
        for(int i = 1;i<n;i++)
            allgcd = __gcd(a[i], allgcd);
        int nw = 0,ind = 0, jed = 0;
        llint nsum = -n;
        for(int i = 0;i<n;i++){
            a[i] /= allgcd;
            nsum += a[i];
            if(a[i] == 1) jed++;
            if(a[i]&1) {nw++;ind = i;}
        }
        if(nsum%2 == 1){
            if(koji) printf("First\n");
            else printf("Second");
            break;
        }
        else if(nw == 1 && !jed){
            a[ind]--;
            continue;
        }
        else{
            if(!koji) printf("First\n");
            else printf("Second");
            break;
        }
    }
    return 0;
}