#include <bits/stdc++.h>
using namespace std;

int N;
int dubling[22][100005];
int X[100005];
int L;
int main()
{
        cin >> N;
        
        for ( int i = 0; i < N; i++ ) cin >> X[i];
        cin >> L;
        for ( int i = 0; i < N; i++ ) {
                dubling[0][i] = upper_bound(X, X + N, X[i] + L) - X - 1;
                //cout << dubling[0][i] << " ";
        }
        //cout << endl;
        
        for ( int p = 1; p < 22; p++ ) {
                for ( int i = 0; i < N; i++ ) {
                        dubling[p][i] = dubling[p - 1][dubling[p - 1][i]];
                        //cout << p << " " << i << " " << dubling[p][i] << endl;
                }
        }
        
        int Q;
        cin >> Q;
        while ( Q-- ) {
                int a, b;
                cin >> a >> b; --a, --b;
                if ( a > b ) swap(a, b);
                int bit = 0;
                int node = a;
                for ( int p = 21; p >= 0; p-- ) {
                        if ( dubling[p][node] < b ) {
                                node = dubling[p][node];
                                bit |= (1 << p);
                        }
                }
                cout << bit + 1 << endl;
        }

        return ( 0 );
}
