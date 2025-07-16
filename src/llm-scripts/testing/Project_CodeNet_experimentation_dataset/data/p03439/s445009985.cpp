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
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
using namespace std;

int Getinput(){
    string s; cin >> s;
    if(s == "Vacant") return 0;
    else if(s == "Male") return 1;
    else if(s == "Female") return 2;
}
int main(){
    int N; cin >> N;

    cout << N - 1 << endl;
    if(Getinput() == 0){
        return 0;
    }
    cout << 0 << endl;
    int x = Getinput();
    if(x == 0){
        return 0;
    }

    int low = 0,high = N - 1;
    int stnd = x;

    while(high - low > 2){
        int mid = (high + low) / 2;
        if(mid % 2 == 1) mid--;

        cout << mid << endl;
        int y = Getinput();
        if(y == 0){
            return 0;
        }else if(stnd == y){
            low = mid;
        }else{
            high = mid;
        }
    }

    cout << low + 1 << endl;
    int z = Getinput();
    return 0;
}