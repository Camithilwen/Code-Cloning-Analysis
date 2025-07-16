#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    double a,b; cin >> a >> b;
    int sum = 0;
    int i = 0;
    while (i < 2) {
        if (a > b) {
            sum += a;
            a--;
        } else {
            sum += b;
            b--;
        }
        i++;
    }
    cout << sum << endl;
}