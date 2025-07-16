#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,Q;
    while( cin >> N >> Q, N||Q ){
        vector<int> date(100, 0);
        for(int i = 0; i < N; i++){
            int m;
            cin >> m;
            for(int j = 0; j < m; j++){
                int a;
                cin >> a;
                date[a] += 1;
            }
        }
        int most_conv, max_v = 0;
        for(int i = 0; i < 100; i++){
            if( date[i] > max_v ){
                most_conv = i;
                max_v = date[i];
            }
        }
        if( max_v >= Q ) cout << most_conv << endl;
        else cout << 0 << endl;
    }
    return 0;
}