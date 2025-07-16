#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
    int n , k;
    cin >> n >> k;
    int s , t;
    s = k + n;
    t = k - n + 1;
    rep2(i,t,s)cout << i << " " ;
}