#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int N,H,W;
    cin >>N>>H>>W;
    int ans = (N-H+1) * (N-W+1);
    cout << ans << endl;
}
