#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <math.h> // sqrt()
#include <iomanip>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n, it, it2;
    it = 0;
    it2 = 0;
    char a;
    cin >> n;
    int sum = n;
    vector<char> str;
    rep(i , n){
        cin >> a;
        str.push_back(a);
    }
    rep(i , n){
        if (i == 0){
            
            it2 = int(count(str.begin() + 1, str.end(), 'E'));
        }
        else{
            if (str.at(i - 1) == 'W')
                it++;
            if (str.at(i) == 'E')
                it2--;
        }
        
        
        sum = min(sum , it + it2);
        
    }
    cout << sum  << endl;
    
}
