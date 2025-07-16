#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main(){
    int N;
    cin >> N;
    int sum = 0;
    double ave = 0;
    double mini = 100;
    double aa = 0;
    int ans = 0;
    vector<int> a(N);
    for(int i = 0;i < N;i++){
        cin >> a.at(i);
        sum += a.at(i);
    }
    ave =  (double)sum/(double)N;
    /*cout << ave << endl;*/

    for(int i = 0;i < N;i++){
        aa = abs(ave - a.at(i));
        if(mini > aa){
            mini = aa;
            
            ans = i;
        }
    }
    cout << ans << endl;
}
