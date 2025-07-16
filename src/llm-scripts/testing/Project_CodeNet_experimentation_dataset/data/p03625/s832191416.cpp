#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <chrono>
#include <numeric>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18+1;
const ll DIV = 1000000007;
//#define TEST
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef TEST
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
#endif
    long N;
    cin >> N;
    map<long, long> A;
    for(size_t i=0;i<N; i++)
    {
        long a;
        cin >> a;
        A[a]++;
    }
    ll max_area = 0;
    ll first_edge=0,second_edge =0;
    for(auto a:A)
    {
        if(a.second >=2)
        {
            if(first_edge == 0) first_edge = a.first;
            if(a.second >= 4)
            {
                first_edge = a.first;
                second_edge = a.first;
            }else
            {
                first_edge = second_edge;
                second_edge = a.first;
            }

        }
        if(first_edge != 0 && second_edge != 0) max_area = max(max_area, first_edge * second_edge);
    }
    cout << max_area << endl;
#ifdef TEST
    end = chrono::system_clock::now();
    cerr << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << endl;
#endif
    return 0;
}