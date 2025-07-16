#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<double> a(n);
    double sum = 0;
    for(int i = 0;i < n;i++){
          cin >> a[i];
          sum += a[i];
    }
    double ave = sum / n;
    double t = 101;
    int ans = -1;
    for(int i = a.size() - 1;i >= 0;i--){
          if(t >= abs(ave - a[i])){
                 t = abs(ave - a[i]);
                 ans = i;
          }
    }
    cout << ans << endl;
    
}
