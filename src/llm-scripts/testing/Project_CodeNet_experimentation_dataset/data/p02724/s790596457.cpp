#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <numeric>
#define ll long long 
#define wolfe ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define elif else if
using namespace std;
int main () {
    wolfe;
    int n;
    cin >> n;
    int sum = 0;
    while(n>=500) {
        n -= 500;
        sum += 1000;
    }
    while(n>=5) {
        n -=5;
        sum += 5;
    }
    cout << sum << endl;
    return 0;
}