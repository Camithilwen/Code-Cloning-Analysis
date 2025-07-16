#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1e9 + 7;
const long long INF = 1LL << 60;

int main() 
{
    int n; cin >> n;
    if(n==2){
        int a,b;
        cin >> a >> b;
        for(int i = 1; i <= min(a,b); i++){
            if(a % i == 0 && b % i == 0){
                cout << i << endl;
            }
        }
    }else{
        int a,b,c;
        cin >> a >> b >> c;
        for(int i = 1; i <= min({a,b,c}); i++){
            if(a % i == 0 && b % i == 0 && c % i == 0){
                cout << i << endl;
            }
        }
    }
}
