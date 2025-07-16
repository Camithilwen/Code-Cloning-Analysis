//#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    long long int n;
    cin >> n;

    //全ての合計
    long long int sum = 0;
    for(int i = 1; i <= n; i++) sum += i;

    //３で割れる
    long long int group_3 = 0;
    for(int i = 3; i <= n; i += 3) group_3 += i;

    //５で割れる
    long long int group_5 = 0;
    for(int i = 5; i <= n; i += 5) group_5 += i;

    //３と５で割れる
    long long int group_3_5 = 0;
    for(int i = 15; i <= n; i += 15) group_3_5 += i;

    long long int ans = sum - group_3 - group_5 + group_3_5;
    cout << ans << endl;
}