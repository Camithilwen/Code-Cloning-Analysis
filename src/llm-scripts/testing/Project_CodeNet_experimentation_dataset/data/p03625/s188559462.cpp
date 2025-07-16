#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, p, l, c;
long long A[100100];

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>A[i];
    }
    sort(A+1,A+N+1);
    for(int i=N; i>=1; i--) {
        if(A[i]==A[i-1]) {
            p=A[i];
            c=i-2;
            break;
        }
    }
    for (int i=c; i>=1; i--) {
        if(A[i]==A[i-1]) {
            l=A[i];
            break;
        }
    }
    cout<<p*l<<endl;
}