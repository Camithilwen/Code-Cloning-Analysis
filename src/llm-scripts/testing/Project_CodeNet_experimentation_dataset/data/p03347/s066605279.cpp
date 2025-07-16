#include <iostream>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int B[N];
    long ans = 0;
    for(int i=0; i<N; i++){
        if(i-A[i]<0){
            cout << -1 << endl;
            return 0;
        }
        B[i] = i - A[i];
    }

    for(int i=1; i<N; i++){
        if(B[i]<B[i-1]) {
            cout << -1 << endl;
            return 0;
        }
        if(B[i-1]<B[i])ans += (i-1) - B[i-1];
    }
    ans += (N-1)-B[N-1];
    cout << ans << endl;

    return 0;
}
