#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int x = 0;
    cin >> x;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }

    int ans = 0;
    sort(A.begin(),A.end());
    for (size_t i = 0; i < N; i++)
    {
       // cout << x << endl;
        x -= A.at(i);
        //cout << x << endl;
        if (x < 0){
            break;
        }
        //cout << 52345234 << endl;
        ans++;
        /* code */
        
    }
    if(x>0)ans--;
    cout << ans << endl;
    

    return 0;
}