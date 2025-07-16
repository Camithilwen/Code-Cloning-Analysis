#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}

void solve(){
    int n, k;
    cin >> n >> k;
    set<int> d;
    for(int i = 0 ; i < 10; i++){
        d.insert(i);
    }
    for(int i = 0 ; i < k; i++){
        int x;
        cin >>  x;
        d.erase(x);
    }
    int p[5];
    for(int i = 0 ; i < 5 ; i++){
        p[i] = 0;
    }
    int j;
    for(j = 4 ; j >= 0; j--){
        p[j] = n % 10;
        n = n / 10;
        if( n == 0 ) break;
    }
    int i;
    for(i = j ; i < 5 ; i++){
        if( d.find(p[i]) == d.end()){
            break; 
        }else{
            continue;
        }
    }
    int smallest_digit = *d.lower_bound(0);
    auto it = d.lower_bound(p[i]);
    if ( it == d.end()){
        int update_index = i - 1;
        while ( d.lower_bound(p[update_index] + 1) == d.end()){
            update_index--;
        }
        p[update_index] = *d.lower_bound(p[update_index] + 1);
        int ans = 0;
        for(int k = 0 ; k < 5 ; k++){
            if( k <= update_index){
                ans = ans * 10 + p[k];
            }else{
                ans = ans * 10 + smallest_digit;
            }
        }
        cout << ans << endl;
        return;
    }

    p[i] = *it;

    int ans = 0;
    for( int k = 0 ; k < 5 ; k++){
        if( k <= i ){
            ans = ans * 10 + p[k];
        }else{
            ans = ans * 10 + smallest_digit;
        }
    } 

    cout << ans << endl;
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}
