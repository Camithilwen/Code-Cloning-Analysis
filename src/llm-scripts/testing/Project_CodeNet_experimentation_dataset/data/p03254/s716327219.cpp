#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(void){
    int N,X;
    cin >> N >> X;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int ans=0;
    for(int i=0;i<N;i++){
        if(i==N-1){
            if(A[i]==X){
                ans++;
            }
            X-=X;
        }
        if(A[i]<=X){
            X -= A[i];
            ans++;
        }else{
            cout << ans << endl;
            return 0;
        }
    }
	return 0;
}
