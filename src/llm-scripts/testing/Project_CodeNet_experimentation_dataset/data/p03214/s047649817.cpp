#include <iostream>
#include <vector>
using namespace std;

double fabs (double n) {
    if (n < 0) return -n;
    else return n;
}

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    double sum = 0.0;
    for (int i=0; i<n; i++) {
        double num;
        cin >> num;
        a[i] = num;
        sum += num;
    }
    double ave = sum / n;
    double mind = 1000;
    int ans = -1;
    for (int i=0; i<n; i++) {
        if (fabs(a[i]-ave) < mind) {
            mind = fabs(a[i]-ave);
            ans = i;
        }
    }
    cout << ans << endl;
}