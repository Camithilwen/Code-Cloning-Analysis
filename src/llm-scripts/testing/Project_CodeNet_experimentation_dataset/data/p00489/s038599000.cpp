#include <iostream>

using namespace std;

int main()
{
    int pts[101] = {};
    int n;
    cin >> n;

    int const rn = n * ( n - 1 ) / 2;
    for( int i=0; i<rn; ++i ) {
        int ca, cb, pa, pb;
        cin >> ca >> cb >> pa >> pb;
        if ( pa > pb ) {
            pts[ca-1] += 3;
        } else if ( pb > pa ) {
            pts[cb-1] += 3;
        } else if ( pa == pb ){
            pts[ca-1] += 1;
            pts[cb-1] += 1;
        }
    }

    int rank[101] = {};
    int last = -1, rk=0, tr = 1;
    for( int i=0; i<n; ++i ) {
        int mm = 0, r = -1;
        for( int j=0; j<n; ++j ) {
            if ( pts[j] > mm ) {
                mm = pts[j];
                r = j;
            }
        }
        if ( mm == last ) {
            ++tr;
        } else {
            rk += tr > 0 ? tr : 1;
            tr = 1;
        }
        rank[r] = rk;
        last = mm;
        pts[r] = -1;
    }

    
    for( int i=0; i<n; ++i ) {
        cout << rank[i] << endl;
    }
}