#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int l[m], r[m];
    for(int i=0; i<m; i++){
        cin >> l[i] >> r[i];
    }

    int l_prime = *max_element(l, l+m);
    int r_prime = *min_element(r, r+m);

    if(l_prime > r_prime){
        cout << '0' << endl;
        return 0;
    }

    cout << r_prime - l_prime + 1 << endl;

    return 0;
}