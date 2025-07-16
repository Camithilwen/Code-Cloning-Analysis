#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<int> l(Q), r(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> l[i] >> r[i];
    }

    vector<int> acCount(N);
    acCount[0] = 0;
    for (int i = 1; i < N; i++)
    {
        if(S[i] == 'C' && S[i-1] == 'A'){
            acCount[i] = acCount[i-1]+1;
        } else {
            acCount[i] = acCount[i-1];
        }
    }
    
    for (int i = 0; i < Q; i++)
    {
        cout << acCount[r[i]-1] - acCount[l[i]-1] << endl;
    }
    
    
    return 0;
}
