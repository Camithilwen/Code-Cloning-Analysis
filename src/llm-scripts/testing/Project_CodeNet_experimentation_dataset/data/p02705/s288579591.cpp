#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    
    int R;
    cin >> R;
    double ans = (2 * R) * acos(-1.0);
    
    cout << setprecision(20) << ans << endl;

}
