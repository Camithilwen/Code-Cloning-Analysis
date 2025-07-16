#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
    string a, b ,c;
    cin >> a >> b >> c;
    if(a.back() == b.front() && b.back() == c.front()){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}