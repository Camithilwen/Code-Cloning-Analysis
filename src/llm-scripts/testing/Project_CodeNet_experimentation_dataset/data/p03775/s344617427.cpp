#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
long long F(long long A){ 
    long long ta = A;
    long long fa = 0;
    for(int i = 0; i <= 10; i++){
        if(ta <= 0) break;
        ta /= 10;
        fa++;
    }
    return fa;
}
int main() {
    long long N;
    cin >> N;
    long long n = sqrt(N);
    long long min = 10;
    for(int i = 1; i <= n; i++){
        if(N%i == 0){
            long long A = i;
            long long B = N / i;
            long long m;
            if(F(A) > F(B)) m = F(A);
            else m = F(B);
            if(min > m) min = m;
        }
    }
    cout << min << endl;
    return 0;
}