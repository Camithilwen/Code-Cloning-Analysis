#include <iostream>
using namespace std;

#include <cmath>
int main(){
    int n,x,t; cin >> n >> x >> t;
    cout << (long long)ceil((double)n/x)*t << endl;
}