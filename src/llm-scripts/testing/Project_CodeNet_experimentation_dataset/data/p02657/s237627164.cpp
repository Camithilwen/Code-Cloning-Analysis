#include<iostream>
#include<cstring>
using namespace std;
double eps = 1e-5;
int main() {
    long long a;
    double b;
    string s;
    cin >> a;
    cin >> b;
    cout <<  (long long)(a * (long long)(b*100 + eps * 100)) / 100;
   // system("pause");
}