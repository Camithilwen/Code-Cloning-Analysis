#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n,d,v;
    cin >> n >> d >> v;
    double time = (double)n/v;
    if(time <= d) cout << "Yes" << endl;
    else cout << "No" << endl;
}